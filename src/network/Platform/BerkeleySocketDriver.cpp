#include "Platform/BerkeleySocketDriver.h"
#include "Platform/InetAddress.h"

// NON-DECOMPED

namespace Quazal {
    BerkeleySocketDriver::BerkeleySocket::~BerkeleySocket() {}
    s32 BerkeleySocketDriver::BerkeleySocket::Open(SocketDriver::_TrafficType) {
        return 0;
    }
    s32 BerkeleySocketDriver::BerkeleySocket::Bind(u16) { return 0; }
    s32 BerkeleySocketDriver::BerkeleySocket::
        RecvFrom(u8 *, unsigned int, InetAddress *, s32 *) {
        return 0;
    }
    s32
    BerkeleySocketDriver::BerkeleySocket::SendTo(u8 *, unsigned int, InetAddress *, s32 *) {
        return 0;
    }
    void BerkeleySocketDriver::BerkeleySocket::Connect() {};
    s32 BerkeleySocketDriver::BerkeleySocket::Recv(u8 *, unsigned int, s32 *) {
        return 0;
    }
    s32 BerkeleySocketDriver::BerkeleySocket::Send(u8 *, unsigned int, s32 *) {
        return 0;
    }
}