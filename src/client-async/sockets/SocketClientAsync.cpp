/*
 *  Copyright (c) 2014-2015 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License
 */
/**
 * @file        src/client-async/sockets/SocketClientAsync.cpp
 * @author      Marcin Niesluchowski <m.niesluchow@samsung.com>
 * @version     1.0
 * @brief       This file contains definition of cynara's socket asynchronous
 *              client
 */

#include <request/Request.h>
#include <request/RequestContext.h>

#include "SocketClientAsync.h"

namespace Cynara {

SocketClientAsync::SocketClientAsync(const std::string &socketPath, ProtocolPtr protocol)
    : m_socket(socketPath, 0), m_protocol(protocol) {
    m_readQueue = std::make_shared<BinaryQueue>();
    m_writeQueue = std::make_shared<BinaryQueue>();
}

Socket::ConnectionStatus SocketClientAsync::connect(void) {
    Socket::ConnectionStatus status = m_socket.connect();
    if (status != Socket::ConnectionStatus::ALREADY_CONNECTED)
        clear();
    return status;
}

Socket::ConnectionStatus SocketClientAsync::completeConnection(void) {
    Socket::ConnectionStatus status = m_socket.completeConnection();
    if (status == Socket::ConnectionStatus::CONNECTION_FAILED)
        clear();
    return status;
}

int SocketClientAsync::getSockFd(void) {
    return m_socket.getSockFd();
}

bool SocketClientAsync::isConnected(void) {
    return m_socket.isConnected();
}

void SocketClientAsync::appendRequest(const Request &request) {
    RequestContext context(ResponseTakerPtr(), m_writeQueue);
    request.execute(*m_protocol, context);
}

bool SocketClientAsync::isDataToSend(void) {
    return m_socket.isDataToSend() || !m_writeQueue->empty();
}

Socket::SendStatus SocketClientAsync::sendToCynara(void) {
    return m_socket.sendToServer(*m_writeQueue);
}

bool SocketClientAsync::receiveFromCynara(void) {
    return m_socket.receiveFromServer(*m_readQueue);
}

ResponsePtr SocketClientAsync::getResponse(void) {
    return m_protocol->extractResponseFromBuffer(m_readQueue);
}

void SocketClientAsync::clear(void)
{
    m_readQueue->clear();
    m_writeQueue->clear();
}

} // namespace Cynara
