/*********************                                                        */
/*! \file modes.h
 ** \verbatim
 ** Original author: Andrew Reynolds
 ** Major contributors: Morgan Deters
 ** Minor contributors (to current version): none
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2014  New York University and The University of Iowa
 ** See the file COPYING in the top-level source directory for licensing
 ** information.\endverbatim
 **
 ** \brief [[ Add one-line brief description here ]]
 **
 ** [[ Add lengthier description here ]]
 ** \todo document this file
 **/

#include "cvc4_public.h"

#ifndef __CVC4__PRINTER__MODES_H
#define __CVC4__PRINTER__MODES_H

#include <iostream>

namespace CVC4 {

/** Enumeration of model_format modes (how to print models from get-model command). */
typedef enum {
  /** default mode (print expressions in the output language format) */
  MODEL_FORMAT_MODE_DEFAULT,
  /** print functional values in a table format */
  MODEL_FORMAT_MODE_TABLE,
} ModelFormatMode;

/** Enumeration of inst_format modes (how to print models from get-model command). */
typedef enum {
  /** default mode (print expressions in the output language format) */
  INST_FORMAT_MODE_DEFAULT,
  /** print as SZS proof */
  INST_FORMAT_MODE_SZS,
} InstFormatMode;

std::ostream& operator<<(std::ostream& out, ModelFormatMode mode) CVC4_PUBLIC;
std::ostream& operator<<(std::ostream& out, InstFormatMode mode) CVC4_PUBLIC;

}/* CVC4 namespace */

#endif /* __CVC4__PRINTER__MODEL_FORMAT_H */
