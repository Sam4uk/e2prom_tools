#include <curl/curl.h>
#include <sysexits.h>

#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

#include "IntelHex.hpp"
#include "build_defs.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

constexpr uint32_t k_max_uint32_t = 0xFFFFFFFF;
constexpr uint32_t k_max_corect_number = 0xF5C309FF;
constexpr uint32_t k_min_corect_number =
    (BUILD_YEAR_CH2 * 10 + BUILD_YEAR_CH3 - 1) * 1000 +
    (BUILD_MONTH_CH0 * 10 + BUILD_MONTH_CH1 - 1) * 100000 +
    (BUILD_DAY_CH0 * 10 + BUILD_DAY_CH0 - 1) * 10000000;

void SerialMessage(uint32_t num) {
std::cout<<"             "<<num<<std::endl;
}

// 0010123001;
int main(void) {
  CURL *curl;
  CURLcode res;
#ifndef NANIT_SERIAL_NUMBER_URL
#error NO URLS
#else
  std::string readBuffer;
#endif
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, NANIT_SERIAL_NUMBER_URL);
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
    SerialMessage(sn);
    std::cout << IHEX_RECORD(125, bytes, sizeof(sn), DATA_TYPE::RECORD_DAT)
              << IHEX_RECORD();
    // 010122001
  }
  return 0;
}