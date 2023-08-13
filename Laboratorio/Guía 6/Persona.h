#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
    private:
        string nombre;
        string apellido;
    public:
        Persona(string n, string a){
            this->nombre = n;
            this->apellido = a;
        }
        string getNombre(){
            return this->nombre;
        }
        void setNombre(string n){
            this->nombre = n;
        }
        string getApellido(){
            return this->apellido;
        }
        void setApellido(string a){
            this->apellido = a;
        }
        virtual string getTipoPersona(){
            return getTipoPersona();
        }
};

#endif // PERSONA_H_INCLUDED
