#include <stdlib.h>
#include <stdio.h>

/* Include the mruby header */
#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/string.h>

int main(void)
{
  mrb_state *mrb = mrb_open();
  
  struct RClass* cv = mrb_class_get(mrb, "String");
  mrb_value code = mrb_str_new(mrb, "p 'hello world!'", 16);
  mrb_value str = mrb_obj_new(mrb, cv, 1, &code);

  printf("str#size is %d \n", mrb_funcall(mrb, str, "size", 0, 0));

  printf("str is '%s' \n", RSTRING_PTR(str));

  mrb_load_string(mrb, RSTRING_PTR(str));
  return 0;
}

