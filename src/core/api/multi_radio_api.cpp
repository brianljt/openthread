/*
 *  Copyright (c) 2020, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *   This file implements the OpenThread Multi Radio Link APIs.
 */

#include "openthread-core-config.h"

#if OPENTHREAD_CONFIG_MULTI_RADIO

#include <openthread/multi_radio.h>

#include "common/code_utils.hpp"
#include "common/debug.hpp"
#include "common/instance.hpp"
#include "common/locator-getters.hpp"
#include "thread/radio_selector.hpp"

using namespace ot;

otError otMultiRadioGetNeighborInfo(otInstance *              aInstance,
                                    const otExtAddress *      aExtAddress,
                                    otMultiRadioNeighborInfo *aInfo)
{
    Error     error    = kErrorNone;
    Instance &instance = *static_cast<Instance *>(aInstance);
    Neighbor *neighbor;

    neighbor = instance.Get<NeighborTable>().FindNeighbor(*static_cast<const Mac::ExtAddress *>(aExtAddress),
                                                          Neighbor::kInStateAnyExceptInvalid);
    VerifyOrExit(neighbor != NULL, error = kErrorNotFound);

    neighbor->PopulateMultiRadioInfo(*aInfo);

exit:
    return error;
}
#endif // OPENTHREAD_CONFIG_MULTI_RADIO
