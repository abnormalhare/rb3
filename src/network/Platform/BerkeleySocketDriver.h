#pragma once

#include "Platform/CriticalSection.h"
#include "Platform/RootObject.h"
#include "Platform/InetAddress.h"
#include "types.h"

namespace Quazal {
    class SocketDriver : public InetAddress {
    public:
        enum _TrafficType {
        };
    };

    class BerkeleySocketDriver {
    public:
        class BerkeleySocket : RootObject {
        public:
            ~BerkeleySocket();
            virtual s32 Open(SocketDriver::_TrafficType);
            virtual void Close();
            virtual s32 Bind(u16);
            virtual s32 RecvFrom(u8 *, unsigned int, InetAddress *, s32 *); // recv
            virtual s32 SendTo(u8 *, unsigned int, InetAddress *, s32 *); // send
            virtual void Connect();
            virtual s32 Recv(u8 *, unsigned int, s32 *); // recv
            virtual s32 Send(u8 *, unsigned int, s32 *); // send

            char unk4[0x4];
            CriticalSection unk8;
        };
        virtual void SetMulticastAddress(unsigned int);
        virtual BerkeleySocket *Create();
        virtual void Delete(BerkeleySocket *);
    };
}