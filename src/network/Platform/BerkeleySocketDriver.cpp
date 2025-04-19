#include "Platform/BerkeleySocketDriver.h"

// NON-DECOMPED

namespace Quazal {
    BerkeleySocketDriver::BerkeleySocket::~BerkeleySocket() {}
    s32 BerkeleySocketDriver::BerkeleySocket::Open(SocketDriver::_TrafficType) {
        return 0;
    }
    s32 BerkeleySocketDriver::BerkeleySocket::Bind(u16) { return 0; }
    s32 unk14(u8 *, u32, s32 *, s32 *) { return 0; }
    s32 unk18(u8 *, u32, s32 *, s32 *) { return 0; }
    void unk1C() {};
    s32 unk20(u8 *, u32, s32 *, s32 *) { return 0; }
    s32 unk24(u8 *, u32, s32 *, s32 *) { return 0; }
}