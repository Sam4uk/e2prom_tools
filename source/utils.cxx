#include "utils.hxx"

#include <iostream>

std::string PutMes(std::string mes, std::string s = " ") {
  std::string resilt = "";
  for (size_t b = 0; b != mes.size(); ++b) {
    resilt += mes[b] + s;
  }
  return resilt;
}

std::string stringRepeat(size_t times, std::string str) {
  std::string result = "";
  for (size_t c = 0; c != times; ++c) result += str;
  return result;
}

void SerialMessage(uint32_t num) {
  // 1010123000num
  std::string s_number(std::to_string(num));
  const std::string line{"--"};
  const std::string space{"  "};
  const std::string TopLeft{"/"};
  const std::string TopRight{"\\"};
  const std::string ButtomLeft{"\\"};
  const std::string ButtomRigth{"/"};
  const uint8_t sl = 4;
  const uint8_t tabs = 4;
  // s_number.size();
  std::cout << std::endl

            << stringRepeat(tabs, space) << "/" << stringRepeat(sl, line)
            << stringRepeat(s_number.size(), "--") << stringRepeat(sl, line)
            << "\\" << std::endl

            << stringRepeat(tabs, space) << "|"
            << stringRepeat(sl * 2 + s_number.size(), space) << "|" << std::endl

            << stringRepeat(tabs, space) << "|" << stringRepeat(sl, space)
            << PutMes(s_number) << stringRepeat(sl, space) << "|" << std::endl

            << stringRepeat(tabs, space) << "|"
            << stringRepeat(sl * 2 + s_number.size(), space) << "|" << std::endl

            << stringRepeat(tabs, space) << "\\" << stringRepeat(sl, line)
            << stringRepeat(s_number.size(), line) << stringRepeat(sl, line)
            << "/" << std::endl;
}
