/*********************                                                        */
/*! \file options_handlers.h
 ** \verbatim
 ** Original author: Morgan Deters
 ** Major contributors: Andrew Reynolds
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

#include "cvc4_private.h"

#ifndef __CVC4__THEORY__QUANTIFIERS__OPTIONS_HANDLERS_H
#define __CVC4__THEORY__QUANTIFIERS__OPTIONS_HANDLERS_H

#include <string>

namespace CVC4 {
namespace theory {
namespace quantifiers {

static const std::string instWhenHelp = "\
Modes currently supported by the --inst-when option:\n\
\n\
full-last-call (default)\n\
+ Alternate running instantiation rounds at full effort and last\n\
  call.  In other words, interleave instantiation and theory combination.\n\
\n\
full\n\
+ Run instantiation round at full effort, before theory combination.\n\
\n\
full-delay \n\
+ Run instantiation round at full effort, before theory combination, after\n\
  all other theories have finished.\n\
\n\
last-call\n\
+ Run instantiation at last call effort, after theory combination and\n\
  and theories report sat.\n\
\n\
";

static const std::string literalMatchHelp = "\
Literal match modes currently supported by the --literal-match option:\n\
\n\
none (default)\n\
+ Do not use literal matching.\n\
\n\
predicate\n\
+ Consider the phase requirements of predicate literals when applying heuristic\n\
  quantifier instantiation.  For example, the trigger P( x ) in the quantified \n\
  formula forall( x ). ( P( x ) V ~Q( x ) ) will only be matched with ground\n\
  terms P( t ) where P( t ) is in the equivalence class of false, and likewise\n\
  Q( x ) with Q( s ) where Q( s ) is in the equivalence class of true.\n\
\n\
";

static const std::string axiomInstModeHelp = "\
Axiom instantiation modes currently supported by the --axiom-inst option:\n\
\n\
default \n\
+ Treat axioms the same as usual quantifiers, i.e. use all available methods for\n\
  instantiating axioms.\n\
\n\
trust \n\
+ Treat axioms only using heuristic instantiation.  Return unknown if in the case\n\
  that no instantiations are produced.\n\
\n\
priority \n\
+ Treat axioms only using heuristic instantiation.  Resort to using all methods\n\
  in the case that no instantiations are produced.\n\
\n\
";

static const std::string mbqiModeHelp = "\
Model-based quantifier instantiation modes currently supported by the --mbqi option:\n\
\n\
default \n\
+ Use algorithm from Section 5.4.2 of thesis Finite Model Finding in Satisfiability \n\
  Modulo Theories.\n\
\n\
none \n\
+ Disable model-based quantifier instantiation.\n\
\n\
gen-ev \n\
+ Use model-based quantifier instantiation algorithm from CADE 24 finite\n\
  model finding paper based on generalizing evaluations.\n\
\n\
fmc-interval \n\
+ Same as default, but with intervals for models of integer functions.\n\
\n\
abs \n\
+ Use abstract MBQI algorithm (uses disjoint sets). \n\
\n\
";
static const std::string qcfWhenModeHelp = "\
Quantifier conflict find modes currently supported by the --quant-cf-when option:\n\
\n\
default \n\
+ Default, apply conflict finding at full effort.\n\
\n\
last-call \n\
+ Apply conflict finding at last call, after theory combination and \n\
  and all theories report sat. \n\
\n\
std \n\
+ Apply conflict finding at standard effort.\n\
\n\
std-h \n\
+ Apply conflict finding at standard effort when heuristic says to. \n\
\n\
";
static const std::string qcfModeHelp = "\
Quantifier conflict find modes currently supported by the --quant-cf option:\n\
\n\
prop-eq \n\
+ Default, apply QCF algorithm to propagate equalities as well as conflicts. \n\
\n\
conflict \n\
+ Apply QCF algorithm to find conflicts only.\n\
\n\
partial \n\
+ Apply QCF algorithm to instantiate heuristically as well. \n\
\n\
mc \n\
+ Apply QCF algorithm in a complete way, so that a model is ensured when it fails. \n\
\n\
";
static const std::string userPatModeHelp = "\
User pattern modes currently supported by the --user-pat option:\n\
\n\
trust \n\
+ When provided, use only user-provided patterns for a quantified formula.\n\
\n\
use \n\
+ Use both user-provided and auto-generated patterns when patterns\n\
  are provided for a quantified formula.\n\
\n\
resort \n\
+ Use user-provided patterns only after auto-generated patterns saturate.\n\
\n\
ignore \n\
+ Ignore user-provided patterns. \n\
\n\
";
static const std::string triggerSelModeHelp = "\
Trigger selection modes currently supported by the --trigger-sel option:\n\
\n\
default \n\
+ Default, consider all subterms of quantified formulas for trigger selection.\n\
\n\
min \n\
+ Consider only minimal subterms that meet criteria for triggers.\n\
\n\
max \n\
+ Consider only maximal subterms that meet criteria for triggers. \n\
\n\
";
static const std::string prenexQuantModeHelp = "\
Prenex quantifiers modes currently supported by the --prenex-quant option:\n\
\n\
default \n\
+ Default, prenex all nested quantifiers except those with user patterns.\n\
\n\
all \n\
+ Prenex all nested quantifiers.\n\
\n\
none \n\
+ Do no prenex nested quantifiers. \n\
\n\
";
static const std::string cegqiFairModeHelp = "\
Modes for enforcing fairness for counterexample guided quantifier instantion, supported by --cegqi-fair:\n\
\n\
uf-dt-size \n\
+ Enforce fairness using an uninterpreted function for datatypes size.\n\
\n\
default | dt-size \n\
+ Default, enforce fairness using size theory operator.\n\
\n\
dt-height-bound \n\
+ Enforce fairness by height bound predicate.\n\
\n\
none \n\
+ Do not enforce fairness. \n\
\n\
";
static const std::string termDbModeHelp = "\
Modes for term database, supported by --term-db-mode:\n\
\n\
all  \n\
+ Quantifiers module considers all ground terms.\n\
\n\
relevant \n\
+ Quantifiers module considers only ground terms connected to current assertions. \n\
\n\
";

inline InstWhenMode stringToInstWhenMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg == "pre-full") {
    return INST_WHEN_PRE_FULL;
  } else if(optarg == "full") {
    return INST_WHEN_FULL;
  } else if(optarg == "full-delay") {
    return INST_WHEN_FULL_DELAY;
  } else if(optarg == "full-last-call") {
    return INST_WHEN_FULL_LAST_CALL;
  } else if(optarg == "last-call") {
    return INST_WHEN_LAST_CALL;
  } else if(optarg == "help") {
    puts(instWhenHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --inst-when: `") +
                          optarg + "'.  Try --inst-when help.");
  }
}

inline void checkInstWhenMode(std::string option, InstWhenMode mode, SmtEngine* smt) throw(OptionException) {
  if(mode == INST_WHEN_PRE_FULL) {
    throw OptionException(std::string("Mode pre-full for ") + option + " is not supported in this release.");
  }
}

inline LiteralMatchMode stringToLiteralMatchMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg ==  "none") {
    return LITERAL_MATCH_NONE;
  } else if(optarg ==  "predicate") {
    return LITERAL_MATCH_PREDICATE;
  } else if(optarg ==  "equality") {
    return LITERAL_MATCH_EQUALITY;
  } else if(optarg ==  "help") {
    puts(literalMatchHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --literal-matching: `") +
                          optarg + "'.  Try --literal-matching help.");
  }
}

inline void checkLiteralMatchMode(std::string option, LiteralMatchMode mode, SmtEngine* smt) throw(OptionException) {
  if(mode == LITERAL_MATCH_EQUALITY) {
    throw OptionException(std::string("Mode equality for ") + option + " is not supported in this release.");
  }
}

inline AxiomInstMode stringToAxiomInstMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg ==  "default") {
    return AXIOM_INST_MODE_DEFAULT;
  } else if(optarg ==  "trust") {
    return AXIOM_INST_MODE_TRUST;
  } else if(optarg ==  "priority") {
    return AXIOM_INST_MODE_PRIORITY;
  } else if(optarg ==  "help") {
    puts(axiomInstModeHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --axiom-inst: `") +
                          optarg + "'.  Try --axiom-inst help.");
  }
}

inline MbqiMode stringToMbqiMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg == "gen-ev") {
    return MBQI_GEN_EVAL;
  } else if(optarg == "none") {
    return MBQI_NONE;
  } else if(optarg == "default" || optarg ==  "fmc") {
    return MBQI_FMC;
  } else if(optarg == "fmc-interval") {
    return MBQI_FMC_INTERVAL;
  } else if(optarg == "abs") {
    return MBQI_ABS;
  } else if(optarg == "trust") {
    return MBQI_TRUST;
  } else if(optarg == "help") {
    puts(mbqiModeHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --mbqi: `") +
                          optarg + "'.  Try --mbqi help.");
  }
}

inline void checkMbqiMode(std::string option, MbqiMode mode, SmtEngine* smt) throw(OptionException) {

}

inline QcfWhenMode stringToQcfWhenMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg ==  "default") {
    return QCF_WHEN_MODE_DEFAULT;
  } else if(optarg ==  "last-call") {
    return QCF_WHEN_MODE_LAST_CALL;
  } else if(optarg ==  "std") {
    return QCF_WHEN_MODE_STD;
  } else if(optarg ==  "std-h") {
    return QCF_WHEN_MODE_STD_H;
  } else if(optarg ==  "help") {
    puts(qcfWhenModeHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --quant-cf-when: `") +
                          optarg + "'.  Try --quant-cf-when help.");
  }
}
inline QcfMode stringToQcfMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg ==  "conflict") {
    return QCF_CONFLICT_ONLY;
  } else if(optarg ==  "default" || optarg == "prop-eq") {
    return QCF_PROP_EQ;
  } else if(optarg == "partial") {
    return QCF_PARTIAL;
  } else if(optarg == "mc" ) {
    return QCF_MC;
  } else if(optarg ==  "help") {
    puts(qcfModeHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --quant-cf-mode: `") +
                          optarg + "'.  Try --quant-cf-mode help.");
  }
}

inline UserPatMode stringToUserPatMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg == "use") {
    return USER_PAT_MODE_USE;
  } else if(optarg ==  "default" || optarg == "trust") {
    return USER_PAT_MODE_TRUST;
  } else if(optarg == "resort") {
    return USER_PAT_MODE_RESORT;
  } else if(optarg == "ignore") {
    return USER_PAT_MODE_IGNORE;
  } else if(optarg ==  "help") {
    puts(userPatModeHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --user-pat: `") +
                          optarg + "'.  Try --user-pat help.");
  }
}

inline TriggerSelMode stringToTriggerSelMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg ==  "default" || optarg == "all" ) {
    return TRIGGER_SEL_DEFAULT;
  } else if(optarg == "min") {
    return TRIGGER_SEL_MIN;
  } else if(optarg == "max") {
    return TRIGGER_SEL_MAX;
  } else if(optarg ==  "help") {
    puts(triggerSelModeHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --trigger-sel: `") +
                          optarg + "'.  Try --trigger-sel help.");
  }
}

inline PrenexQuantMode stringToPrenexQuantMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg ==  "default" ) {
    return PRENEX_NO_USER_PAT;
  } else if(optarg == "all") {
    return PRENEX_ALL;
  } else if(optarg == "none") {
    return PRENEX_NONE;
  } else if(optarg ==  "help") {
    puts(prenexQuantModeHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --prenex-quant: `") +
                          optarg + "'.  Try --prenex-quant help.");
  }
}

inline CegqiFairMode stringToCegqiFairMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg == "uf-dt-size" ) {
    return CEGQI_FAIR_UF_DT_SIZE;
  } else if(optarg == "default" || optarg == "dt-size") {
    return CEGQI_FAIR_DT_SIZE;
  } else if(optarg == "dt-height-bound" ){
    return CEGQI_FAIR_DT_HEIGHT_PRED;
  } else if(optarg == "none") {
    return CEGQI_FAIR_NONE;
  } else if(optarg ==  "help") {
    puts(cegqiFairModeHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --cegqi-fair: `") +
                          optarg + "'.  Try --cegqi-fair help.");
  }
}

inline TermDbMode stringToTermDbMode(std::string option, std::string optarg, SmtEngine* smt) throw(OptionException) {
  if(optarg == "all" ) {
    return TERM_DB_ALL;
  } else if(optarg == "relevant") {
    return TERM_DB_RELEVANT;
  } else if(optarg ==  "help") {
    puts(termDbModeHelp.c_str());
    exit(1);
  } else {
    throw OptionException(std::string("unknown option for --term-db-mode: `") +
                          optarg + "'.  Try --term-db-mode help.");
  }
}

}/* CVC4::theory::quantifiers namespace */
}/* CVC4::theory namespace */
}/* CVC4 namespace */

#endif /* __CVC4__THEORY__QUANTIFIERS__OPTIONS_HANDLERS_H */
