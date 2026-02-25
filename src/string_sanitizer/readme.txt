Le pedí al chatgpt que me haga una batería de tests,
 el makefile y un header por pereza a tener que hacer todo eso para probar mis dos archivos...
 Hasta ahora parece que no tiene leaks y funciona como debería. Antes de usar el sanitizer habría que
 borrar la funcion de testing de string_sanitizer.c y struct_counting.c

 Tambien la funcion de testing entera

 hay que hacer free de la linea de readline/gnl antes de devolver el array
 de estructuras