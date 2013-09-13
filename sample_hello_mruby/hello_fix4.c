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
  mrb_value str = mrb_obj_new(mrb, cv, 0, 0);
  
  mrb_value head = mrb_str_new(mrb,"p 'hello",8);
  mrb_value tail = mrb_str_new(mrb," world'",7);

  str = mrb_funcall_argv(mrb, str, mrb_intern2(mrb, "+", 1), 1, &head);
  str = mrb_funcall_argv(mrb, str, mrb_intern2(mrb, "+", 1), 1, &tail);

  printf("str#size is %d \n", mrb_funcall(mrb, str, "size", 0, 0));
  printf("str is '%s' \n", RSTRING_PTR(str));

  mrb_load_string(mrb, RSTRING_PTR(str));
  return 0;
}

