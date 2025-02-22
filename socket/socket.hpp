#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <cstdint>
#include <vector>

void send_packet(const std::vector<uint8_t>& packet);

#endif
