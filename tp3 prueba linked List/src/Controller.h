int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_findIdMax(LinkedList* pArrayListEmployee, int* id);
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id, int* gotIndex);


int controller_elEmpleadoTrabajaMayora200(void* pElement);// filter
int controller_CuantosEmpleadosGananMenosDe17000(void* pElement);//count

int employee_imprimirEmp(void* pElement);

int controller_ListEmployee2(LinkedList* pArrayListEmployee);


