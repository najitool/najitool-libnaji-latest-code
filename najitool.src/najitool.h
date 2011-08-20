#ifndef __NAJITOOL_H__NAJI__
#define __NAJITOOL_H__NAJI__

/* ---------- */
/* najitool.h */
/* ---------- */

/* najitool main header */

/* this  .h  is a part of */
/* najitool version 0.8.3 */

/* from najitool version 0.2.0 and */
/* above najitool will use libnaji */
/* this version uses libnaji 0.6.3 */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

#include "libnaji.h"

#define NAJITOOL_MAX_COMMANDS 203

extern const char * najitool_valid_commands[NAJITOOL_MAX_COMMANDS];


/* #define NAJI_DEBUG */

void forhelp(void);
void naji_stdin_msg(void);
void najitool_check_command(char *cmd);
void najitool_command_help(char *cmd);
void najitool_generate_help(void);
void najitool_generate_help_html(void);
void najitool_help_commands(void);
void notparam(char *cmd);
void tooparam(char *cmd);

#endif /* __NAJITOOL_H__NAJI__ */
