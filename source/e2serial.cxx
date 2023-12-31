#include <curl/curl.h>
#include <sysexits.h>

#include <args/args.hxx>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

#include "IntelHex.hpp"
#include "build_defs.h"
#include "utils.hxx"

// https :  // docs.ieu.edu.ua/seriynyk.php?SN=1

#ifndef NANIT_SCHEME
#error Не визначені  важливі константи перевірте налашутвання компіляції
#endif

static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

#define HOST  "docs.ieu.edu.ua"
#define PATH  "seriynyk.php"
#define QUERY "SN=1"
const std::string scheme{NANIT_SCHEME}, host{HOST}, path{PATH}, query{QUERY};

constexpr uint32_t k_max_uint32_t = 0xFFFFFFFF;
constexpr uint32_t k_max_corect_number = 0xF5C309FF;
constexpr uint32_t k_min_corect_number =
    (BUILD_YEAR_CH2 * 10 + BUILD_YEAR_CH3 - 1) * 1000 +
    (BUILD_MONTH_CH0 * 10 + BUILD_MONTH_CH1 - 1) * 100000 +
    (BUILD_DAY_CH0 * 10 + BUILD_DAY_CH0 - 1) * 10000000;

static const std::string About{
    "This program receives the serial number from the servers and generates a "
    "serial number for the Nanites. Also registers or deletes an invalid "
    "number"};
static const std::string CopyRigth{"The author of this program Sam4uk"};
static const std::string SamtingIsWrong{"Something is wrong"};


int main(int argc, char const *argv[]) try
/*
Запускаємо програму і одразу починаємо ловити виняткові ситуації щоб красиво
впасити
*/
{
  // std::cout << scheme;
  args::ArgumentParser parser(About, CopyRigth);
  args::Group group(
      parser, "This group is all exclusive:", args::Group::Validators::Xor);
  args::Flag foo(group, "foo", "The foo flag", {'f', "foo"});
  args::Flag bar(group, "bar", "The bar flag", {'b'});
  args::Flag baz(group, "baz", "The baz flag", {"baz"});
  try
  /*
  Це вкладеий try
  */
  {
    parser.ParseCLI(argc, argv);
  }

  catch (args::Help) {
    std::cout << parser;
    return 0;
  }

  catch (args::ParseError e) {
    std::cerr << e.what() << std::endl;
    std::cerr << parser;
    return 1;
  }

  catch (args::ValidationError e) {
    std::cerr << e.what() << std::endl;
    std::cerr << parser;
    return 1;
  }

  catch (...) {
    // впав парсинг CLI
    return 1;
  }
  if (foo) {
    std::cout << "foo" << std::endl;
  }
  if (bar) {
    std::cout << "bar" << std::endl;
  }
  if (baz) {
    CURL *curl;
    CURLcode res;
    // #ifndef NANIT_SERIAL_NUMBER_URL
    // #error NO URLS
    // #else
    std::string readBuffer;
    // #endif

    curl = curl_easy_init();
    if (curl) {
      std::string q{scheme + "://" + host + '/' + path + '?' + query};
      curl_easy_setopt(curl, CURLOPT_URL,
                       "https://docs.ieu.edu.ua/seriynyk.php?SN=1");
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
      // std::cout << k_max_uint32_t << std::endl;
      // std::cout << std::stoll(readBuffer) << std::endl;
      // std::cout << k_min_corect_number << std::endl;

      int64_t serial_number = std::stoll(readBuffer);
      // Перевірити номер на коректність
      if (k_max_uint32_t < serial_number) {
        //   std::cout << "To big";
        return EX_IOERR;
      }
      if (k_max_corect_number < serial_number) {
        //   std::cout << "big";
        return EX_IOERR;
      }
      if (k_min_corect_number > serial_number) {
        //   std::cout << "small";
        return EX_IOERR;
      }
      union {
        uint32_t sn;
        char bytes[sizeof(sn)];
      };
      sn = serial_number;

      std::string filename{"./nanit_serial.hex"};
      try
      // ловимо помилки доступу при спробі записати файл
      {
        std::ofstream hex_out;
        hex_out.open(filename);
        hex_out << IHEX_RECORD(uint16_t(0xfff) - sizeof(sn) + 1, bytes,
                               sizeof(sn), DATA_TYPE::RECORD_DAT)
                << IHEX_RECORD();
        hex_out.close();

      } catch (...) {
      }
      // avrdude -c wiring -p m2560 -b 152000 -U eeprom:w:CLEAR_EEPROM.hex:i
      std::string p{"avrdude3"};
      std::string programmer{"usbtiny"};
      std::string chip{"m2560"};
      std::string speed{"152000"};
      // std::string eeprom{filename};
      std::string command{p + " -c " + programmer + " -p " + chip +
                          " -D -U eeprom:w:" + filename + ":i"};
      auto err{system(command.c_str())};
      if (!err) {
        // serial=46546&status=ok
        std::string rm{"rm " + filename};
        SerialMessage(sn);
        std::cout << "OK" << std::endl;
        // system(rm.c_str());
      } else
        switch (err) {
          case 32512:
          throw std::invalid_argument("Cant find programm");
            // std::cout << std::endl
            //           << "\t !!!\n\t   Cant find programm" << err << std::endl;
            break;

          default: {
            std::cout << std::endl
                      << "\t !!!\n\t   Write error. Check the cable connections"
                      << err << std::endl;
            // serial=456456&status=fail
          } break;
        }
      // std::cout << err << std::endl;
    }
    // std::cout << "baz" << std::endl;
  }
  return EX_OK;
}

catch (const std::invalid_argument &e) {
  std::cout << e.what() << std::endl;
}

catch (const std::exception &e) {
  std::cerr << e.what() << std::endl;
}

catch (...) {
  std::cerr << SamtingIsWrong << std::endl;
  return -1;
}