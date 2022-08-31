/*
 * Generated by erpcgen 1.9.1 on Wed Aug 31 15:16:23 2022.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "qspi_rad_test_server.h"
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include <new>
#include "erpc_port.h"
#endif
#include "erpc_manually_constructed.hpp"

#if 10901 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;

#if ERPC_NESTED_CALLS_DETECTION
extern bool nestingDetection;
#endif

ERPC_MANUALLY_CONSTRUCTED_STATIC(QSPIService_service, s_QSPIService_service);



// Call the correct server shim based on method unique ID.
erpc_status_t QSPIService_service::handleInvocation(uint32_t methodId, uint32_t sequence, Codec * codec, MessageBufferFactory *messageFactory)
{
    erpc_status_t erpcStatus;
    switch (methodId)
    {
        case kQSPIService_sectorErase_id:
        {
            erpcStatus = sectorErase_shim(codec, messageFactory, sequence);
            break;
        }

        case kQSPIService_pageRead_id:
        {
            erpcStatus = pageRead_shim(codec, messageFactory, sequence);
            break;
        }

        case kQSPIService_pageWrite_id:
        {
            erpcStatus = pageWrite_shim(codec, messageFactory, sequence);
            break;
        }

        default:
        {
            erpcStatus = kErpcStatus_InvalidArgument;
            break;
        }
    }

    return erpcStatus;
}

// Server shim for sectorErase of QSPIService interface.
erpc_status_t QSPIService_service::sectorErase_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    uint32_t addr;
    int32_t result;

    // startReadMessage() was already called before this shim was invoked.

    codec->read(&addr);

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        result = sectorErase(addr);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kQSPIService_service_id, kQSPIService_sectorErase_id, sequence);

        codec->write(result);

        err = codec->getStatus();
    }

    return err;
}

// Server shim for pageRead of QSPIService interface.
erpc_status_t QSPIService_service::pageRead_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    uint32_t addr;
    uint8_t data[256];
    int32_t result;

    // startReadMessage() was already called before this shim was invoked.

    codec->read(&addr);

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        result = pageRead(addr, data);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kQSPIService_service_id, kQSPIService_pageRead_id, sequence);

        for (uint32_t arrayCount0 = 0U; arrayCount0 < 256U; ++arrayCount0)
        {
            codec->write(data[arrayCount0]);
        }

        codec->write(result);

        err = codec->getStatus();
    }

    return err;
}

// Server shim for pageWrite of QSPIService interface.
erpc_status_t QSPIService_service::pageWrite_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    uint32_t addr;
    uint8_t data[256];
    int32_t result;

    // startReadMessage() was already called before this shim was invoked.

    codec->read(&addr);

    for (uint32_t arrayCount0 = 0U; arrayCount0 < 256U; ++arrayCount0)
    {
        codec->read(&data[arrayCount0]);
    }

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        result = pageWrite(addr, data);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kQSPIService_service_id, kQSPIService_pageWrite_id, sequence);

        codec->write(result);

        err = codec->getStatus();
    }

    return err;
}

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
erpc_service_t create_QSPIService_service()
{
    return new (nothrow) QSPIService_service();
}

void destroy_QSPIService_service(erpc_service_t service)
{
    if (service)
    {
        delete (QSPIService_service *)service;
    }
}
#elif ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_STATIC
erpc_service_t create_QSPIService_service()
{
    s_QSPIService_service.construct();
    return s_QSPIService_service.get();
}

void destroy_QSPIService_service()
{
    s_QSPIService_service.destroy();
}
#else
#warning "Unknown eRPC allocation policy!"
#endif