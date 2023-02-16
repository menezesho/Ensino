//sistema de cadastro de cursos, alunos, professores e aulas

#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

struct tipoCurso {
    string nome, tipo;
    int duracao;
} typedef tcurso;

struct tipoProfessor {
    string nome;
    int cpf, idade, cracha;
} typedef tprof;

struct tipoAluno {
    string nome;
    int cpf, idade, matricula;
} typedef taluno;


//funcoes

void cadastrarCurso(tcurso curso[20], int *qtdCursos) {
    bool igual=false;
    cout<<endl<<"CADASTRO DE CURSO:"<<endl;
    cout<<endl<<"Nome do curso: ";
    cin>>curso[*qtdCursos].nome;
    for(int i=0; i<*qtdCursos; i++) 
        if(curso[*qtdCursos].nome == curso[i].nome)
            igual=true;
    if(igual) {
        system("cls");
        cout<<endl<<"CURSO JA CADASTRADO, TENTE NOVAMENTE!"<<endl;
    }
    else {
        cout<<"Tipo do curso: ";
        cin>>curso[*qtdCursos].tipo;
        cout<<"Duracao (em horas) do curso: ";
        cin>>curso[*qtdCursos].duracao;
        system("cls");
        cout<<endl<<"CADASTRO EFETUADO COM SUCESSO!"<<endl;
        (*qtdCursos)++;
    }
}
void listarCurso(tcurso curso[20], int *qtdCursos) {
    if(*qtdCursos<1) {
        system("cls");
        cout<<endl<<"NENHUM CURSO FOI CADASTRADO!";
    }
    else {
        system("cls");
        cout<<endl<<"LISTA DE CURSOS:"<<endl;
        for(int i=0; i<*qtdCursos; i++) {
            cout<<endl<<"- CURSO "<<i+1<<": "<<endl;
            cout<<"Nome: "<<curso[i].nome<<endl;
            cout<<"Tipo: "<<curso[i].tipo<<endl;
            cout<<"Duracao: "<<curso[i].duracao<<"h"<<endl;
        }
    }
}
void editarCurso(tcurso curso[20], int *qtdCursos) {
    string qualCurso, novoNomeTipo;
    int qualInfo=0, novaDuracao=0;
    bool achou=false, igual=false;
    if(*qtdCursos<1) {
        system("cls");
        cout<<endl<<"NENHUM CURSO FOI CADASTRADO!"<<endl;
    }
    else {
        system("cls");
        cout<<endl<<"Qual curso deseja editar? ";
        cin>>qualCurso;
        for(int i=0; i<*qtdCursos; i++) {
            if(qualCurso==curso[i].nome)
                achou=true;
        }
        if(!achou) {
            system("cls");
            cout<<endl<<"O CURSO INFORMADO NAO ESTA CADASTRADO!"<<endl;
        }
        else {
            system("cls");
            cout<<endl<<"Qual informacao deseja editar?"<<endl;
            cout<<"1. Nome"<<endl;
            cout<<"2. Tipo"<<endl;
            cout<<"3. Duracao"<<endl;
            cout<<"Opcao: ";
            cin>>qualInfo;
            if(qualInfo==1) {
                for(int i=0; i<*qtdCursos; i++) {
                    if(qualCurso==curso[i].nome) {
                        system("cls");
                        cout<<"Qual será o novo nome do curso? ";
                        cin>>novoNomeTipo;
                        for(int j=0; j<*qtdCursos; j++) {
                            if(novoNomeTipo == curso[j].nome) {
                                igual=true;
                                break;
                            }
                        }
                        if(!igual) {
                            curso[i].nome = novoNomeTipo;
                            system("cls");
                            cout<<endl<<"NOME ALTERADO COM SUCESSO!"<<endl;
                        }
                        else {
                            system("cls");
                            cout<<endl<<"CURSO DE MESMO NOME EXISTENTE, TENTE NOVAMENTE!"<<endl;
                        }
                    }
                }
            }
            else if(qualInfo==2) {
                for(int i=0; i<*qtdCursos; i++) {
                    if(qualCurso==curso[i].nome) {
                        system("cls");
                        cout<<endl<<"Qual será o novo tipo do curso? ";
                        cin>>novoNomeTipo;
                        curso[i].tipo = novoNomeTipo;
                        system("cls");
                        cout<<endl<<"TIPO ALTERADO COM SUCESSO!"<<endl;
                    }
                }
            }
            else if(qualInfo==3) {
                for(int i=0; i<*qtdCursos; i++) {
                    if(qualCurso==curso[i].nome) {
                        system("cls");
                        cout<<endl<<"Qual será a nova duracao do curso? ";
                        cin>>novaDuracao;
                        curso[i].duracao = novaDuracao;
                        system("cls");
                        cout<<endl<<"DURACAO ALTERADA COM SUCESSO!"<<endl;
                    }
                }
            }
            else {
                system("cls");
                cout<<endl<<"OPCAO INVALIDA, TENTE NOVAMENTE!"<<endl;
            }
        }
    }
}
void excluirCurso(tcurso curso[20], int *qtdCursos) {
    string qualCurso;
    bool achou=false;
    if(*qtdCursos<1) {
        system("cls");
        cout<<endl<<"NENHUM CURSO FOI CADASTRADO!"<<endl;
    }
    else {
        system("cls");
        cout<<endl<<"Qual curso deseja excluir? ";
        cin>>qualCurso;
        for(int i=0; i<*qtdCursos; i++)
            if(qualCurso==curso[i].nome)
                achou=true;
        if(!achou) {
            system("cls");
            cout<<endl<<"O CURSO INFORMADO NAO ESTA CADASTRADO!"<<endl;
        }
        else {
            if(qualCurso==curso[0].nome){
                for(int i=0; i<*qtdCursos+1; i++) {
                    curso[i].nome = curso[i+1].nome;
                    curso[i].tipo = curso[i+1].tipo;
                    curso[i].duracao = curso[i+1].duracao;
                    system("cls");
                    cout<<endl<<"CURSO EXCLUIDO COM SUCESSO!"<<endl;
                }
                (*qtdCursos)--;
            }
            else {
                for(int i=0; i<*qtdCursos; i++) {
                    while(qualCurso==curso[i].nome) {
                        curso[i].nome = curso[i+1].nome;
                        curso[i].tipo = curso[i+1].tipo;
                        curso[i].duracao = curso[i+1].duracao;
                        system("cls");
                        cout<<endl<<"CURSO EXCLUIDO COM SUCESSO!"<<endl;
                        (*qtdCursos)--;
                    }
                }
            }
        }
    }
}

void cadastrarProfessor(tprof prof[20], int *qtdProfs) {
    bool igual=false;
    cout<<endl<<"CADASTRO DE PROFESSOR:"<<endl;
    cout<<endl<<"Crachá do professor: ";
    cin>>prof[*qtdProfs].cracha;
    for(int i=0; i<*qtdProfs; i++) 
        if(prof[*qtdProfs].cracha == prof[i].cracha)
            igual=true;
    if(igual) {
            system("cls");
            cout<<endl<<"PROFESSOR JA CADASTRADO, TENTE NOVAMENTE!"<<endl;
    }
    else {
        cout<<"Nome do professor: ";
        cin>>prof[*qtdProfs].nome;
        cout<<"CPF do professor: ";
        cin>>prof[*qtdProfs].cpf;
        cout<<"Idade do professor: ";
        cin>>prof[*qtdProfs].idade;
        system("cls");
        cout<<endl<<"CADASTRO EFETUADO COM SUCESSO!"<<endl;
        (*qtdProfs)++;
    }
}
void listarProfessor(tprof prof[20], int *qtdProfs) {
    if(*qtdProfs<1) {
        system("cls");
        cout<<endl<<"NENHUM PROFESSOR FOI CADASTRADO!";
    }
    else {
        system("cls");
        cout<<endl<<"LISTA DE PROFESSORES:"<<endl;
        for(int i=0; i<*qtdProfs; i++) {
            cout<<endl<<"- CURSO "<<i+1<<": "<<endl;
            cout<<"Crachá: "<<prof[i].cracha<<endl;
            cout<<"Nome: "<<prof[i].nome<<endl;
            cout<<"CPF: "<<prof[i].cpf<<endl;
            cout<<"Idade: "<<prof[i].idade<<endl;
        }
    }
}
void editarProfessor(tprof prof[20], int *qtdProfs) {
    string novoNome;
    int qualProf=0, qualInfo=0, novoCpfIdadeCracha=0;
    bool achou=false, igual=false;
    if(*qtdProfs<1) {
        system("cls");
        cout<<endl<<"NENHUM PROFESSOR FOI CADASTRADO!"<<endl;
    }
    else {
        system("cls");
        cout<<endl<<"Qual o numero do cracha do cadastro que deseja editar? ";
        cin>>qualProf;
        for(int i=0; i<*qtdProfs; i++) {
            if(qualProf==prof[i].cracha)
                achou=true;
        }
        if(!achou) {
            system("cls");
            cout<<endl<<"O PROFESSOR INFORMADO NAO ESTA CADASTRADO!"<<endl;
        }
        else {
            system("cls");
            cout<<endl<<"Qual informacao deseja editar?"<<endl;
            cout<<"1. Craha"<<endl;
            cout<<"2. Nome"<<endl;
            cout<<"3. CPF"<<endl;
            cout<<"4. Idade"<<endl;
            cout<<"Opcao: ";
            cin>>qualInfo;
            if(qualInfo==1){
                for(int i=0; i<*qtdProfs; i++) {
                    if(qualProf==prof[i].cracha) {
                        system("cls");
                        cout<<"Qual será o novo numero de cracha do professor? ";
                        cin>>novoCpfIdadeCracha;
                        for(int j=0; j<*qtdProfs; j++) {
                            if(novoCpfIdadeCracha == prof[j].cracha) {
                                igual=true;
                                break;
                            }
                        }
                        if(!igual) {
                            prof[i].cracha = novoCpfIdadeCracha;
                            system("cls");
                            cout<<endl<<"CRACHA ALTERADO COM SUCESSO!"<<endl;
                        }
                        else {
                            system("cls");
                            cout<<endl<<"NUMERO DE CRACHA JA EXISTENTE, TENTE NOVAMENTE!"<<endl;
                        }
                    }
                }
            }
            else if(qualInfo==2) {
                for(int i=0; i<*qtdProfs; i++) {
                    if(qualProf==prof[i].cracha) {
                        system("cls");
                        cout<<"Qual será o novo nome do professor? ";
                        cin>>novoNome;
                        for(int j=0; j<*qtdProfs; j++) {
                            if(novoNome == prof[j].nome) {
                                igual=true;
                                break;
                            }
                        }
                        if(!igual) {
                            prof[i].nome = novoNome;
                            system("cls");
                            cout<<endl<<"NOME ALTERADO COM SUCESSO!"<<endl;
                        }
                        else {
                            system("cls");
                            cout<<endl<<"PROFESSOR DE MESMO NOME JA CADASTRADO, TENTE NOVAMENTE!"<<endl;
                        }
                    }
                }
            }
            else if(qualInfo==3) {
                for(int i=0; i<*qtdProfs; i++) {
                    if(qualProf==prof[i].cracha) {
                        system("cls");
                        cout<<"Qual será o novo CPF do professor? ";
                        cin>>novoCpfIdadeCracha;
                        for(int j=0; j<*qtdProfs; j++) {
                            if(novoCpfIdadeCracha == prof[j].cpf) {
                                igual=true;
                                break;
                            }
                        }
                        if(!igual) {
                            prof[i].cpf = novoCpfIdadeCracha;
                            system("cls");
                            cout<<endl<<"CPF ALTERADO COM SUCESSO!"<<endl;
                        }
                        else {
                            system("cls");
                            cout<<endl<<"PROFESSOR DE MESMO CPF JA CADASTRADO, TENTE NOVAMENTE!"<<endl;
                        }
                    }
                }
            }
            else if(qualInfo==4) {
                for(int i=0; i<*qtdProfs; i++) {
                    if(qualProf==prof[i].cracha) {
                        system("cls");
                        cout<<endl<<"Qual será a nova idade do professor? ";
                        cin>>novoCpfIdadeCracha;
                        prof[i].idade = novoCpfIdadeCracha;
                        system("cls");
                        cout<<endl<<"IDADE ALTERADA COM SUCESSO!"<<endl;
                    }
                }
            }
            else {
                system("cls");
                cout<<endl<<"OPCAO INVALIDA, TENTE NOVAMENTE!"<<endl;
            }
        }
    }
}
void excluirProfessor(tprof prof[20], int *qtdProfs) {
    int qualProf;
    bool achou=false;
    if(*qtdProfs<1) {
        system("cls");
        cout<<endl<<"NENHUM PROFESSOR FOI CADASTRADO!"<<endl;
    }
    else {
        system("cls");
        cout<<endl<<"Qual numero do crachá do professor que deseja excluir? ";
        cin>>qualProf;
        for(int i=0; i<*qtdProfs; i++)
            if(qualProf==prof[i].cracha)
                achou=true;
        if(!achou) {
            system("cls");
            cout<<endl<<"O PROFESSOR INFORMADO NAO ESTA CADASTRADO!"<<endl;
        }
        else {
            if(qualProf==prof[0].cracha){
                for(int i=0; i<*qtdProfs+1; i++) {
                    prof[i].cracha = prof[i+1].cracha;
                    prof[i].nome = prof[i+1].nome;
                    prof[i].cpf = prof[i+1].cpf;
                    prof[i].idade = prof[i+1].idade;
                    system("cls");
                    cout<<endl<<"PROFESSOR EXCLUIDO COM SUCESSO!"<<endl;
                }
                (*qtdProfs)--;
            }
            else {
                for(int i=0; i<*qtdProfs; i++) {
                    while(qualProf==prof[i].cracha) {
                        prof[i].cracha = prof[i+1].cracha;
                        prof[i].nome = prof[i+1].nome;
                        prof[i].cpf = prof[i+1].cpf;
                        prof[i].idade = prof[i+1].idade;
                        system("cls");
                        cout<<endl<<"PROFESSOR EXCLUIDO COM SUCESSO!"<<endl;
                        (*qtdProfs)--;
                    }
                }
            }
        }
    }
}

void cadastrarAluno(taluno aluno[20], int *qtdAlunos) {
    bool igual=false;
    cout<<endl<<"CADASTRO DE ALUNO:"<<endl;
    cout<<endl<<"Matrícula do aluno: ";
    cin>>aluno[*qtdAlunos].matricula;
    for(int i=0; i<*qtdAlunos; i++) 
        if(aluno[*qtdAlunos].matricula == aluno[i].matricula)
            igual=true;
    if(igual) {
            system("cls");
            cout<<endl<<"ALUNO JA CADASTRADO, TENTE NOVAMENTE!"<<endl;
    }
    else {
        cout<<"Nome do aluno: ";
        cin>>aluno[*qtdAlunos].nome;
        cout<<"CPF do aluno: ";
        cin>>aluno[*qtdAlunos].cpf;
        cout<<"Idade do aluno: ";
        cin>>aluno[*qtdAlunos].idade;
        system("cls");
        cout<<endl<<"CADASTRO EFETUADO COM SUCESSO!"<<endl;
        (*qtdAlunos)++;
    }
}
void listarAluno(taluno aluno[20], int *qtdAlunos) {
    if(*qtdAlunos<1) {
        system("cls");
        cout<<endl<<"NENHUM PROFESSOR FOI CADASTRADO!";
    }
    else {
        system("cls");
        cout<<endl<<"LISTA DE PROFESSORES:"<<endl;
        for(int i=0; i<*qtdAlunos; i++) {
            cout<<endl<<"- CURSO "<<i+1<<": "<<endl;
            cout<<"Crachá: "<<aluno[i].matricula<<endl;
            cout<<"Nome: "<<aluno[i].nome<<endl;
            cout<<"CPF: "<<aluno[i].cpf<<endl;
            cout<<"Idade: "<<aluno[i].idade<<endl;
        }
    }
}
void editarAluno(taluno aluno[20], int *qtdAlunos) {
    string novoNome;
    int qualAluno=0, qualInfo=0, novoCpfIdadeMatri=0;
    bool achou=false, igual=false;
    if(*qtdAlunos<1) {
        system("cls");
        cout<<endl<<"NENHUM ALUNO FOI CADASTRADO!"<<endl;
    }
    else {
        system("cls");
        cout<<endl<<"Qual o numero de matricula do cadastro que deseja editar? ";
        cin>>qualAluno;
        for(int i=0; i<*qtdAlunos; i++) {
            if(qualAluno==aluno[i].matricula)
                achou=true;
        }
        if(!achou) {
            system("cls");
            cout<<endl<<"O ALUNO INFORMADO NAO ESTA CADASTRADO!"<<endl;
        }
        else {
            system("cls");
            cout<<endl<<"Qual informacao deseja editar?"<<endl;
            cout<<"1. Matricula"<<endl;
            cout<<"2. Nome"<<endl;
            cout<<"3. CPF"<<endl;
            cout<<"4. Idade"<<endl;
            cout<<"Opcao: ";
            cin>>qualInfo;
            if(qualInfo==1){
                for(int i=0; i<*qtdAlunos; i++) {
                    if(qualAluno==aluno[i].matricula) {
                        system("cls");
                        cout<<"Qual será o novo numero de matricula do professor? ";
                        cin>>novoCpfIdadeMatri;
                        for(int j=0; j<*qtdAlunos; j++) {
                            if(novoCpfIdadeMatri == aluno[j].matricula) {
                                igual=true;
                                break;
                            }
                        }
                        if(!igual) {
                            aluno[i].matricula = novoCpfIdadeMatri;
                            system("cls");
                            cout<<endl<<"MATRICULA ALTERADA COM SUCESSO!"<<endl;
                        }
                        else {
                            system("cls");
                            cout<<endl<<"NUMERO DE MATRICULA JA EXISTENTE, TENTE NOVAMENTE!"<<endl;
                        }
                    }
                }
            }
            else if(qualInfo==2) {
                for(int i=0; i<*qtdAlunos; i++) {
                    if(qualAluno==aluno[i].matricula) {
                        system("cls");
                        cout<<"Qual será o novo nome do aluno? ";
                        cin>>novoNome;
                        for(int j=0; j<*qtdAlunos; j++) {
                            if(novoNome == aluno[j].nome) {
                                igual=true;
                                break;
                            }
                        }
                        if(!igual) {
                            aluno[i].nome = novoNome;
                            system("cls");
                            cout<<endl<<"NOME ALTERADO COM SUCESSO!"<<endl;
                        }
                        else {
                            system("cls");
                            cout<<endl<<"ALUNO DE MESMO NOME JA CADASTRADO, TENTE NOVAMENTE!"<<endl;
                        }
                    }
                }
            }
            else if(qualInfo==3) {
                for(int i=0; i<*qtdAlunos; i++) {
                    if(qualAluno==aluno[i].matricula) {
                        system("cls");
                        cout<<"Qual será o novo CPF do aluno? ";
                        cin>>novoCpfIdadeMatri;
                        for(int j=0; j<*qtdAlunos; j++) {
                            if(novoCpfIdadeMatri == aluno[j].cpf) {
                                igual=true;
                                break;
                            }
                        }
                        if(!igual) {
                            aluno[i].cpf = novoCpfIdadeMatri;
                            system("cls");
                            cout<<endl<<"CPF ALTERADO COM SUCESSO!"<<endl;
                        }
                        else {
                            system("cls");
                            cout<<endl<<"ALUNO DE MESMO CPF JA CADASTRADO, TENTE NOVAMENTE!"<<endl;
                        }
                    }
                }
            }
            else if(qualInfo==4) {
                for(int i=0; i<*qtdAlunos; i++) {
                    if(qualAluno==aluno[i].matricula) {
                        system("cls");
                        cout<<endl<<"Qual será a nova idade do aluno? ";
                        cin>>novoCpfIdadeMatri;
                        aluno[i].idade = novoCpfIdadeMatri;
                        system("cls");
                        cout<<endl<<"IDADE ALTERADA COM SUCESSO!"<<endl;
                    }
                }
            }
            else {
                system("cls");
                cout<<endl<<"OPCAO INVALIDA, TENTE NOVAMENTE!"<<endl;
            }
        }
    }
}
void excluirAluno(taluno aluno[20], int *qtdAlunos) {
    int qualProf;
    bool achou=false;
    if(*qtdAlunos<1) {
        system("cls");
        cout<<endl<<"NENHUM ALUNO FOI CADASTRADO!"<<endl;
    }
    else {
        system("cls");
        cout<<endl<<"Qual numero de matrícula do aluno que deseja excluir? ";
        cin>>qualProf;
        for(int i=0; i<*qtdAlunos; i++)
            if(qualProf==aluno[i].matricula)
                achou=true;
        if(!achou) {
            system("cls");
            cout<<endl<<"O ALUNO INFORMADO NAO ESTA CADASTRADO!"<<endl;
        }
        else {
            if(qualProf==aluno[0].matricula){
                for(int i=0; i<*qtdAlunos+1; i++) {
                    aluno[i].matricula = aluno[i+1].matricula;
                    aluno[i].nome = aluno[i+1].nome;
                    aluno[i].cpf = aluno[i+1].cpf;
                    aluno[i].idade = aluno[i+1].idade;
                    system("cls");
                    cout<<endl<<"PROFESSOR EXCLUIDO COM SUCESSO!"<<endl;
                }
                (*qtdAlunos)--;
            }
            else {
                for(int i=0; i<*qtdAlunos; i++) {
                    while(qualProf==aluno[i].matricula) {
                        aluno[i].matricula = aluno[i+1].matricula;
                        aluno[i].nome = aluno[i+1].nome;
                        aluno[i].cpf = aluno[i+1].cpf;
                        aluno[i].idade = aluno[i+1].idade;
                        system("cls");
                        cout<<endl<<"ALUNO EXCLUIDO COM SUCESSO!"<<endl;
                        (*qtdAlunos)--;
                    }
                }
            }
        }
    }
}


int main() {
    char opMenu;
    int opEscolha;
    int qtdCursos=0;
    int qtdProfs=0;
    int qtdAlunos=0;
    tcurso curso[20];
    tprof prof[20];
    taluno aluno[20];

    do {
        cout<<endl<<"--------------------"<<endl;
        cout<<"MENU"<<endl;
        cout<<"1. Curso"<<endl;
        cout<<"2. Professor"<<endl;
        cout<<"3. Aluno"<<endl;
        cout<<"4. Sair"<<endl;
        cout<<"Opcao: ";
        opMenu = getch();
        switch(opMenu) {
            case '1': //curso
                system("cls");
                cout<<endl<<"Qual operacao deseja realizar?"<<endl;
                cout<<"1. Cadastrar"<<endl;
                cout<<"2. Listar"<<endl;
                cout<<"3. Editar"<<endl;
                cout<<"4. Excluir"<<endl;
                cout<<"5. Retornar"<<endl;
                cout<<"Opcao: ";
                opEscolha = getch();
                system("cls");
                switch(opEscolha) {
                    case '1':
                        cadastrarCurso(curso, &qtdCursos);
                    break;
                    case '2':
                        listarCurso(curso, &qtdCursos);
                    break;
                    case '3':
                        editarCurso(curso, &qtdCursos);
                    break;
                    case '4':
                        excluirCurso(curso, &qtdCursos);
                    break;
                    case '5':
                        cout<<"RETORNANDO..."<<endl;
                    break;
                    default:
                        cout<<endl<<"OPCAO INVALIDA, TENTE NOVAMENTE!"<<endl;
                    break;
                }
            break;
            case '2': //professor
                system("cls");
                cout<<endl<<"Qual operacao deseja realizar?"<<endl;
                cout<<"1. Cadastrar"<<endl;
                cout<<"2. Listar"<<endl;
                cout<<"3. Editar"<<endl;
                cout<<"4. Excluir"<<endl;
                cout<<"5. Retornar"<<endl;
                cout<<"Opcao: ";
                opEscolha = getch();
                system("cls");
                switch(opEscolha) {
                    case '1':
                        cadastrarProfessor(prof, &qtdProfs);
                    break;
                    case '2':
                        listarProfessor(prof, &qtdProfs);
                    break;
                    case '3':
                        editarProfessor(prof, &qtdProfs);
                    break;
                    case '4':
                        excluirProfessor(prof, &qtdProfs);
                    break;
                    case '5':
                        cout<<"RETORNANDO..."<<endl;
                    break;                    
                    default:
                        cout<<endl<<"OPCAO INVALIDA, TENTE NOVAMENTE!"<<endl;
                    break;
                }
            break;
            case '3': //aluno
                system("cls");
                cout<<endl<<"Qual operacao deseja realizar?"<<endl;
                cout<<"1. Cadastrar"<<endl;
                cout<<"2. Listar"<<endl;
                cout<<"3. Editar"<<endl;
                cout<<"4. Excluir"<<endl;
                cout<<"5. Retornar"<<endl;
                cout<<"Opcao: ";
                opEscolha = getch();
                switch(opEscolha) {
                    case '1':
                        cadastrarAluno(aluno, &qtdAlunos);
                    break;
                    case '2':
                        listarAluno(aluno, &qtdAlunos);
                    break;
                    case '3':
                        editarAluno(aluno, &qtdAlunos);
                    break;
                    case '4':
                        excluirAluno(aluno, &qtdAlunos);
                    break;
                    case '5':
                        cout<<"RETORNANDO..."<<endl;
                    break;
                    default:
                        cout<<endl<<"OPCAO INVALIDA, TENTE NOVAMENTE!"<<endl;
                    break;
                }
            break;
            case '4':
                system("cls");
                cout<<endl<<"FINALIZANDO...";
            break;
            default:
                system("cls");
                cout<<endl<<"OPCAO INVALIDA, TENTE NOVAMENTE!"<<endl;
            break;
        }
    } while(opMenu != '4');
}