#pragma once
#ifndef _image_op_inc_hpp_
#define _image_op_inc_hpp_

#ifndef HAVE_GRAY_OP
#define HAVE_GRAY_OP
#include "gray_op.hpp"
#endif

#ifndef HAVE_ADD_OP
#define HAVE_ADD_OP
#include "add_op.hpp"
#endif

#ifndef HAVE_IN_OUT_OP
#define HAVE_IN_OUT_OP
#include "in_out_op.hpp"
#endif

#ifndef HAVE_BINARY_OP
#define HAVE_BINARY_OP
#include "operator_op.hpp"
#endif

#endif