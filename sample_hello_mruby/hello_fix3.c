#include <stdlib.h>
#include <stdio.h>

/* Include the mruby header */
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/string.h>

int main(void)
{
  mrb_state *mrb = mrb_open();
  mrb_value code = mrb_str_new(mrb, "p 'hello world!'", 16);

  printf("code#size is %d \n", mrb_funcall(mrb, code, "size", 0, 0));
  printf("code is '%s' \n", RSTRING_PTR(code));

  mrb_load_string(mrb, RSTRING_PTR(code));
  return 0;
}

