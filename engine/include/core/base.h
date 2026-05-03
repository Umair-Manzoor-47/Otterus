//
// Created by umair on 5/3/2026.
//
#pragma once
#include <core/Common.h>

namespace engine {

    // Rule of 5
    class Base {
    public:
       explicit Base(BaseDesc& desc);
       virtual ~Base();

    protected:
        Base(const Base&) = delete;
        Base(Base&&) = delete;
        Base& operator = (const Base&) = delete;
        Base& operator=(Base&&) = delete;
    };
} // engine


