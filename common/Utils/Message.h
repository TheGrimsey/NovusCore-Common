/*
    MIT License

    Copyright (c) 2018-2019 NovusCore

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
#pragma once
#include <NovusTypes.h>
#include <string>
#include <vector>

enum InputMessages
{
    MSG_IN_EXIT,
    MSG_IN_PRINT,
    MSG_IN_PING,
    MSG_IN_NET_CONNECT,
    MSG_IN_NET_DISCONNECT,
    MSG_IN_NET_PACKET,
    MSG_IN_INTERNAL_NET_PACKET,
    MSG_IN_RELOAD
};

enum OutputMessages
{
    MSG_OUT_EXIT_CONFIRM,
    MSG_OUT_PRINT
};

struct Message
{
    Message()
    {
        code = -1;
        message = nullptr;
        object = nullptr;
    }

    i32 code;
    std::string* message;
    void* object;
};
