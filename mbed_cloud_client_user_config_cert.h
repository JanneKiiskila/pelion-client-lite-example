// ----------------------------------------------------------------------------
// Copyright 2016-2020 ARM Ltd.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------------------------------------------------------


#ifndef MBED_CLOUD_CLIENT_USER_CONFIG_H
#define MBED_CLOUD_CLIENT_USER_CONFIG_H

#define MBED_CLOUD_CLIENT_ENDPOINT_TYPE             "default"
#define MBED_CLOUD_CLIENT_LIFETIME                  86400       /* 24 hours */

#if !defined(MBED_CLOUD_CLIENT_TRANSPORT_MODE_UDP) && !defined(MBED_CLOUD_CLIENT_TRANSPORT_MODE_TCP) && !defined(MBED_CLOUD_CLIENT_TRANSPORT_MODE_UDP_QUEUE)
#define MBED_CLOUD_CLIENT_TRANSPORT_MODE_TCP
#endif

#ifdef MBED_CONF_MBED_CLIENT_SN_COAP_MAX_BLOCKWISE_PAYLOAD_SIZE
    #define SN_COAP_MAX_BLOCKWISE_PAYLOAD_SIZE      MBED_CONF_MBED_CLIENT_SN_COAP_MAX_BLOCKWISE_PAYLOAD_SIZE
#else
    #define SN_COAP_MAX_BLOCKWISE_PAYLOAD_SIZE      512
#endif

#define MBED_CLOUD_CLIENT_SUPPORT_UPDATE

/* Sets the download buffer for update client in bytes (min. 1024 bytes).
 * This must be at least twice the SN_COAP_MAX_BLOCKWISE_PAYLOAD_SIZE value.
 */
#ifdef MBED_CONF_APP_MBED_CLOUD_CLIENT_UPDATE_BUFFER_SIZE
#define MBED_CLOUD_CLIENT_UPDATE_BUFFER MBED_CONF_APP_MBED_CLOUD_CLIENT_UPDATE_BUFFER_SIZE
#else
#define MBED_CLOUD_CLIENT_UPDATE_BUFFER             1024
#endif // #ifdef MBED_CONF_APP_MBED_CLOUD_CLIENT_UPDATE_BUFFER_SIZE

/* Developer flags for Update feature */
#if defined(MBED_CONF_APP_DEVELOPER_MODE) &&  (MBED_CONF_APP_DEVELOPER_MODE == 1)
    #define MBED_CLOUD_DEV_UPDATE_CERT
    #define MBED_CLOUD_DEV_UPDATE_ID
#endif /* MBED_CONF_APP_DEVELOPER_MODE */

#define USER_OMA_OBJECT_FILE "user_oma_lwm2m_object_defs.h"

#define PROTOMAN_SECURITY_ENABLE_CERTIFICATE
#define PROTOMAN_USE_SSL_SESSION_RESUME

#endif /* MBED_CLOUD_CLIENT_USER_CONFIG_H */
