/*
 * Generated by erpcgen 1.9.1 on Wed Aug 31 15:16:23 2022.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "erpc_client_manager.h"
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include "erpc_port.h"
#endif
#include "erpc_codec.hpp"
extern "C"
{
#include "qspi_rad_test.h"
}

#if 10901 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;

extern ClientManager *g_client;


// QSPIService interface sectorErase function client shim.
int32_t sectorErase(uint32_t addr)
{
    erpc_status_t err = kErpcStatus_Success;

    int32_t result;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kInvocationMessage, kQSPIService_service_id, kQSPIService_sectorErase_id, request.getSequence());

        codec->write(addr);

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        codec->read(&result);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kQSPIService_sectorErase_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    if (err != kErpcStatus_Success)
    {
        result = -1;
    }

    return result;
}

// QSPIService interface pageRead function client shim.
int32_t pageRead(uint32_t addr, uint8_t data[256])
{
    erpc_status_t err = kErpcStatus_Success;

    int32_t result;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kInvocationMessage, kQSPIService_service_id, kQSPIService_pageRead_id, request.getSequence());

        codec->write(addr);

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        for (uint32_t arrayCount0 = 0U; arrayCount0 < 256U; ++arrayCount0)
        {
            codec->read(&data[arrayCount0]);
        }

        codec->read(&result);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kQSPIService_pageRead_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    if (err != kErpcStatus_Success)
    {
        result = -1;
    }

    return result;
}

// QSPIService interface pageWrite function client shim.
int32_t pageWrite(uint32_t addr, const uint8_t data[256])
{
    erpc_status_t err = kErpcStatus_Success;

    int32_t result;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(kInvocationMessage, kQSPIService_service_id, kQSPIService_pageWrite_id, request.getSequence());

        codec->write(addr);

        for (uint32_t arrayCount0 = 0U; arrayCount0 < 256U; ++arrayCount0)
        {
            codec->write(data[arrayCount0]);
        }

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        codec->read(&result);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kQSPIService_pageWrite_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    if (err != kErpcStatus_Success)
    {
        result = -1;
    }

    return result;
}
