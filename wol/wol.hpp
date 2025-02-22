#ifndef WOL_HPP
#define WOL_HPP

#include <string>
#include <vector>
#include <cstdint>

std::vector<uint8_t> parse_mac(const std::string& address);
std::vector<uint8_t> magic_packet(std::vector<uint8_t>& packet);

#endif