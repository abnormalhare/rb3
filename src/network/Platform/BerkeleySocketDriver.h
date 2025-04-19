#pragma once

#include "Platform/CriticalSection.h"
#include "Platform/RootObject.h"
#include "types.h"

namespace Quazal {
    class SocketDriver {
    public:
        enum _TrafficType {
        };
    };

    class BerkeleySocketDriver {
    public:
        class BerkeleySocket : public CriticalSection {
        public:
            virtual s32 Open(SocketDriver::_TrafficType);
            virtual ~BerkeleySocket();
            virtual s32 Bind(u16);
            virtual s32 unk14(u8 *, u32, s32 *, s32 *); // recv
            virtual s32 unk18(u8 *, u32, s32 *, s32 *); // send
            virtual void unk1C();
            virtual s32 unk20(u8 *, u32, s32 *); // recv
            virtual s32 unk24(u8 *, u32, s32 *); // send
        };
        virtual void SetMulticastAddress(unsigned int);
        virtual BerkeleySocket *Create();
        virtual void Delete(BerkeleySocket *);
    };
}