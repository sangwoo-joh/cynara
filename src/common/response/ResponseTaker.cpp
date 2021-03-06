/*
 * Copyright (c) 2014-2016 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
/**
 * @file        src/common/response/ResponseTaker.cpp
 * @author      Lukasz Wojciechowski <l.wojciechow@partner.samsung.com>
 * @author      Zofia Abramowska <z.abramowska@samsung.com>
 * @version     1.0
 * @brief       This file implements ResponseTaker class
 */


#include <attributes/attributes.h>
#include <exceptions/NotImplementedException.h>

#include "ResponseTaker.h"

namespace Cynara {

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const AdminCheckResponse &response UNUSED) {
    throw NotImplementedException();
}

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const AgentActionResponse &response UNUSED) {
    throw NotImplementedException();
}

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const AgentRegisterResponse &response UNUSED) {
    throw NotImplementedException();
}

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const CancelResponse &response UNUSED) {
    throw NotImplementedException();
}

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const CheckResponse &response UNUSED) {
    throw NotImplementedException();
}

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const CodeResponse &response UNUSED) {
    throw NotImplementedException();
}

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const DescriptionListResponse &response UNUSED) {
    throw NotImplementedException();
}

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const ListResponse &response UNUSED) {
    throw NotImplementedException();
}

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const MonitorGetEntriesResponse &response UNUSED) {
    throw NotImplementedException();
}

void ResponseTaker::execute(const RequestContext &context UNUSED,
                            const SimpleCheckResponse &response UNUSED) {
    throw NotImplementedException();
}

} // namespace Cynara
