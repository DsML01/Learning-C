typedef struct float_vector FloatVector;
//Como aqui eu já tenho um apelido para a struct, não preciso dar um apelido no arquivo de implementacao

FloatVector *create(int capacity);

void destroy(FloatVector **v);

int size(const FloatVector *v);

int capacity(const FloatVector *v);

float at(const FloatVector *v, int i);

float get(const FloatVector *v, int i);

void append(FloatVector *v, float val);

void set(FloatVector *v, int i, float val);

void print(const FloatVector *v);