/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2022 - Raw Material Software Limited

   JUCE is an open source library subject to commercial or open-source
   licensing.

   By using JUCE, you agree to the terms of both the JUCE 7 End-User License
   Agreement and JUCE Privacy Policy.

   End User License Agreement: www.juce.com/juce-7-licence
   Privacy Policy: www.juce.com/juce-privacy-policy

   Or: You may also use this code under the terms of the GPL v3 (see
   www.gnu.org/licenses).

   JUCE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
   EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
   DISCLAIMED.

  ==============================================================================
*/

namespace juce
{
namespace dsp
{

/**
    This class contains various fast mathematical function approximations.

    @tags{DSP}
*/
struct FastMathApproximations
{
    /** Provides a fast approximation of the function cosh(x) using a Pade approximant
        continued fraction, calculated sample by sample.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -5 and +5 for limiting the error.
    */
    template <typename FloatType>
    static constexpr FloatType cosh (FloatType x) noexcept
    {
        constexpr auto a = FloatType(39251520); constexpr auto b = FloatType(39251520); constexpr auto c = FloatType(1075032);
        constexpr auto d = FloatType(14615); constexpr auto e = FloatType(1154160); constexpr auto f = FloatType(16632);
        constexpr auto g = FloatType(127);
        const auto x2 = x * x;
        const auto numerator = -(a + x2 * (b + x2 * (c + d * x2)));
        const auto denominator = -a + x2 * (e + x2 * (-f + g * x2));
        return numerator / denominator;
    }

    /** Provides a fast approximation of the function cosh(x) using a Pade approximant
        continued fraction, calculated on a whole buffer.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -5 and +5 for limiting the error.
    */
    template <typename FloatType>
    static constexpr void cosh (FloatType* values, size_t numValues) noexcept
    {
        for (size_t i = 0; i < numValues; ++i)
            values[i] = FastMathApproximations::cosh (values[i]);
    }

    /** Provides a fast approximation of the function sinh(x) using a Pade approximant
        continued fraction, calculated sample by sample.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -5 and +5 for limiting the error.
    */
    template <typename FloatType>
    static constexpr FloatType sinh (FloatType x) noexcept
    {
        auto x2 = x * x;
        auto numerator = -x * (11511339840 + x2 * (1640635920 + x2 * (52785432 + x2 * 479249)));
        auto denominator = -11511339840 + x2 * (277920720 + x2 * (-3177720 + x2 * 18361));
        return numerator / denominator;
    }

    /** Provides a fast approximation of the function sinh(x) using a Pade approximant
        continued fraction, calculated on a whole buffer.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -5 and +5 for limiting the error.
    */
    template <typename FloatType>
    static constexpr void sinh (FloatType* values, size_t numValues) noexcept
    {
        for (size_t i = 0; i < numValues; ++i)
            values[i] = FastMathApproximations::sinh (values[i]);
    }

    /** Provides a fast approximation of the function tanh(x) using a Pade approximant
        continued fraction, calculated sample by sample.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -5 and +5 for limiting the error.
    */
    template <typename FloatType>
    static FloatType tanh (FloatType x) noexcept
    {
        auto x2 = x * x;
        auto numerator = x * (135135 + x2 * (17325 + x2 * (378 + x2)));
        auto denominator = 135135 + x2 * (62370 + x2 * (3150 + 28 * x2));
        return numerator / denominator;
    }

    /** Provides a fast approximation of the function tanh(x) using a Pade approximant
        continued fraction, calculated on a whole buffer.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -5 and +5 for limiting the error.
    */
    template <typename FloatType>
    static void tanh (FloatType* values, size_t numValues) noexcept
    {
        for (size_t i = 0; i < numValues; ++i)
            values[i] = FastMathApproximations::tanh (values[i]);
    }

    //==============================================================================
    /** Provides a fast approximation of the function cos(x) using a Pade approximant
        continued fraction, calculated sample by sample.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -pi and +pi for limiting the error.
    */
    template <typename FloatType>
    static FloatType cos (FloatType x) noexcept
    {
        constexpr auto a = FloatType(39251520); constexpr auto b = FloatType(18471600);
        constexpr auto c = FloatType(1075032);  constexpr auto d = FloatType(14615);
        constexpr auto e = FloatType(1154160);  constexpr auto f = FloatType(16632);
        constexpr auto g = FloatType(127);
        const auto x2 = x * x;
        const auto numerator = -(-a + x2 * (b + x2 * (-c + d * x2)));
        const auto denominator = a + x2 * (e + x2 * (f + x2 * g));
        return numerator / denominator;
    }

    /** Provides a fast approximation of the function cos(x) using a Pade approximant
        continued fraction, calculated on a whole buffer.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -pi and +pi for limiting the error.
    */
    template <typename FloatType>
    static void cos (FloatType* values, size_t numValues) noexcept
    {
        for (size_t i = 0; i < numValues; ++i)
            values[i] = FastMathApproximations::cos (values[i]);
    }

    /** Provides a fast approximation of the function sin(x) using a Pade approximant
        continued fraction, calculated sample by sample.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -pi and +pi for limiting the error.
    */
    template <typename FloatType>
    static constexpr FloatType sin (FloatType x) noexcept
    {
        const auto a = FloatType(11511339840); const auto b = FloatType(1640635920); const auto c = FloatType(52785432);
        const auto d = FloatType(479249);      const auto e = FloatType(277920720);  const auto f = FloatType(3177720);
        const auto g = FloatType(18361);
        const auto x2 = x * x;
        const auto numerator = -x * (-a + x2 * (b + x2 * (-c + x2 * d)));
        const auto denominator = a + x2 * (e + x2 * (f + x2 * g));
        return numerator / denominator;
    }

    /** Provides a fast approximation of the function sin(x) using a Pade approximant
        continued fraction, calculated on a whole buffer.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -pi and +pi for limiting the error.
    */
    template <typename FloatType>
    static void sin (FloatType* values, size_t numValues) noexcept
    {
        for (size_t i = 0; i < numValues; ++i)
            values[i] = FastMathApproximations::sin (values[i]);
    }

    /** Provides a fast approximation of the function tan(x) using a Pade approximant
        continued fraction, calculated sample by sample.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -pi/2 and +pi/2 for limiting the error.
    */
    template <typename FloatType>
    static FloatType tan (FloatType x) noexcept
    {
        auto x2 = x * x;
        auto numerator = x * (-135135 + x2 * (17325 + x2 * (-378 + x2)));
        auto denominator = -135135 + x2 * (62370 + x2 * (-3150 + 28 * x2));
        return numerator / denominator;
    }

    /** Provides a fast approximation of the function tan(x) using a Pade approximant
        continued fraction, calculated on a whole buffer.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -pi/2 and +pi/2 for limiting the error.
    */
    template <typename FloatType>
    static void tan (FloatType* values, size_t numValues) noexcept
    {
        for (size_t i = 0; i < numValues; ++i)
            values[i] = FastMathApproximations::tan (values[i]);
    }

    //==============================================================================
    /** Provides a fast approximation of the function exp(x) using a Pade approximant
        continued fraction, calculated sample by sample.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -6 and +4 for limiting the error.
    */
    template <typename FloatType>
    static FloatType exp (FloatType x) noexcept
    {
        auto numerator = 1680 + x * (840 + x * (180 + x * (20 + x)));
        auto denominator = 1680 + x *(-840 + x * (180 + x * (-20 + x)));
        return numerator / denominator;
    }

    /** Provides a fast approximation of the function exp(x) using a Pade approximant
        continued fraction, calculated on a whole buffer.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -6 and +4 for limiting the error.
    */
    template <typename FloatType>
    static void exp (FloatType* values, size_t numValues) noexcept
    {
        for (size_t i = 0; i < numValues; ++i)
            values[i] = FastMathApproximations::exp (values[i]);
    }

    /** Provides a fast approximation of the function log(x+1) using a Pade approximant
        continued fraction, calculated sample by sample.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -0.8 and +5 for limiting the error.
    */
    template <typename FloatType>
    static FloatType logNPlusOne (FloatType x) noexcept
    {
        auto numerator = x * (7560 + x * (15120 + x * (9870 + x * (2310 + x * 137))));
        auto denominator = 7560 + x * (18900 + x * (16800 + x * (6300 + x * (900 + 30 * x))));
        return numerator / denominator;
    }

    /** Provides a fast approximation of the function log(x+1) using a Pade approximant
        continued fraction, calculated on a whole buffer.

        Note: This is an approximation which works on a limited range. You are
        advised to use input values only between -0.8 and +5 for limiting the error.
    */
    template <typename FloatType>
    static void logNPlusOne (FloatType* values, size_t numValues) noexcept
    {
        for (size_t i = 0; i < numValues; ++i)
            values[i] = FastMathApproximations::logNPlusOne (values[i]);
    }
};

} // namespace dsp
} // namespace juce
