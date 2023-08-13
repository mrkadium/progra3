#ifndef MEDIDA_H_INCLUDED
#define MEDIDA_H_INCLUDED

class Medida{
    private:
        int idMedida;
        string unidadMed;
    public:
        Medida(){
        }
        Medida(int idm, string um){
            this->idMedida = idm;
            this->unidadMed = um;
        }
        void setIdMedida(int idm){
            this->idMedida = idm;
        }
        int getIdMedida(){
            return this->idMedida;
        }
        void setUnidadMedida(string um){
            this->unidadMed = um;
        }
        string getUnidadMedida(){
            return this->unidadMed;
        }
};

#endif // MEDIDA_H_INCLUDED
