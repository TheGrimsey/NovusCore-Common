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

namespace Math
{
    const float PI = 3.1415926535f;
    const float HALF_PI = PI / 2.0f;
    const float TAU = 6.2831853071f; // Clearly superior
    const float INV_TAU = 1.0f / TAU;

    float Sqrt(float in);

    constexpr float DegToRad(float deg)
    {
        return (deg * PI) / 180.0f;
    }

    constexpr float RadToDeg(float rad)
    {
        return (rad * 180.0f) / PI;
    }

    inline unsigned int FloorToInt(float x)
    {
        int xi = (int)x;
        return x < xi ? xi - 1 : xi;
    }

    inline float Floor(float x)
    {
        return static_cast<float>(FloorToInt(x));
    }

    inline unsigned int RoofToInt(float x)
    {
        int xi = (int)x;
        return x < xi ? xi + 1 : xi;
    }

    inline unsigned int RoofToInt(double x)
    {
        int xi = (int)x;
        return x < xi ? xi + 1 : xi;
    }

    inline float Roof(float x)
    {
        return static_cast<float>(RoofToInt(x));
    }

    inline double Roof(double x)
    {
        return static_cast<double>(RoofToInt(x));
    }

    inline float Modulus(float a, float b)
    {
        return (a - b * Floor(a / b));
    }

    inline float Abs(float x)
    {
        return x < 0 ? -x : x;
    }

    inline float Hill(float x)
    {
        const float a0 = 1.0f;
        const float a2 = 2.0f / PI - 12.0f / (PI * PI);
        const float a3 = 16.0f / (PI * PI * PI) - 4.0f / (PI * PI);
        const float xx = x * x;
        const float xxx = xx * x;
        return a0 + a2 * xx + a3 * xxx;
    }

    inline float Sin(float x)
    {
        const float a = x * INV_TAU;
        x -= static_cast<signed int>(a) * TAU;
        if (x < 0.0f)
            x += TAU;

        // 4 pieces of hills
        if (x < HALF_PI)
            return Hill(HALF_PI - x);
        else if (x < PI)
            return Hill(x - HALF_PI);
        else if (x < 3.0f * HALF_PI)
            return -Hill(3.0f * HALF_PI - x);
        else
            return -Hill(x - 3.0f * HALF_PI);
    }

    inline float Cos(float x)
    {
        return Sin(x + HALF_PI);
    }

    float Tan(float x);

    inline float Min(float a, float b)
    {
        return (a <= b) ? a : b;
    }

    inline float Max(float a, float b)
    {
        return (a >= b) ? a : b;
    }

    inline int Min(int a, int b)
    {
        return (a <= b) ? a : b;
    }

    inline int Max(int a, int b)
    {
        return (a >= b) ? a : b;
    }

    inline size_t Min(size_t a, size_t b)
    {
        return (a <= b) ? a : b;
    }

    inline size_t Max(size_t a, size_t b)
    {
        return (a >= b) ? a : b;
    }

    inline float Clamp(float x, float min, float max)
    {
        return Max(Min(x, max), min);
    }

    inline int Clamp(int x, int min, int max)
    {
        return Max(Min(x, max), min);
    }

    inline size_t Clamp(size_t x, size_t min, size_t max)
    {
        return Max(Min(x, max), min);
    }

    inline float Lerp(float start, float end, float t)
    {
        return (start + t * (end - start));
    }

    __forceinline float Map(float value, float originalMin, float originalMax, float newMin, float newMax)
    {
        return (value - originalMin) / (originalMax - originalMin) * (newMax - newMin) + newMin;
    }
};