<img align="right" width="80" height="80" src="https://assecom.ufersa.edu.br/wp-content/uploads/sites/24/2014/09/PNG-bras%C3%A3o-Ufersa.png">

<h1 align="center">Clínica Odontológica-OdontoTech</h1>

<br> 

## Navegação do Projeto:

- [Proposta do Projeto](#proposta-do-projeto)
- [Funcionalidades do Projeto](#funcionalidades-do-projeto)
- [Estrutura de Diretórios](#estrutura-de-diretórios-do-projeto)
- [Compilar o Código](#compilar-o-código)
- [Colaboradores](#colaboradores)



# Proposta do Projeto

<p> O objetivo deste projeto é desenvolver um sistema de gerenciamento para clínicas odontológicas, facilitando a organização e o controle de dentistas e pacientes. A plataforma permitirá o cadastro e a gestão dos profissionais da clínica, além de fornecer uma interface eficiente para atender pacientes de forma organizada. Com isso, busca-se otimizar o processo de agendamento, atendimento e gestão de informações, oferecendo uma solução integrada para melhorar a eficiência operacional e a qualidade do serviço prestado.
</p>


# Compilar o código

### Gerar Arquivo Objeto

```
gcc -c src/sistema.c -o sistema.o
gcc -c src/paciente.c -o paciente.o
gcc -c src/dentista.c -o dentista.o
```

### Linkar Objetos e Gerar o Executável

``` 

gcc dentista.o paciente.o sistema.o main.o -o Nome-do-executavel

```

# Funcionalidades do Projeto


```
✅ Adicionar dentista
✅ Buscar dentista
✅ Remover dentista
✅ Adicionar paciente
✅ Atender paciente
✅ Buscar paciente
```

# Estrutura de Diretórios do Projeto

### A organização dos diretórios e arquivos do projeto é a seguinte:

```
Clínica_OdontoTech/
│
├── 📁 include/                   
│   ├── 🦷 dentista.h             
│   ├── 👨‍⚕️ paciente.h           
│   └── ⚙️ sistema.h             
│
├── 📁 src/                       
│   ├── 🦷 dentista.c             
│   ├── 👨‍⚕️ paciente.c            
│   ├── ⚙️ sistema.c              
│   └── 💻 main.c                 
│
├── 📁 output/                    
│   └── 🛠 main.exe               
│
├── 🚫 .gitignore
└── 📄 README.md                 
```

  # Colaboradores
  Um agradecimento especial a todas as pessoas que contribuíram para este projeto.
  <table>
    <tr>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/143232809?v=4" width="100px;" alt="foto de Thyago"/><br>
          <sub>
            <a href="https://github.com/thyagofab"><b>Thyago Fabricio</b></a>
          </sub>
        </a>
      </td>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/146228058?v=4" width="100px;" alt="Foto de Vinícius"/><br>
          <sub>
            <a href="https://github.com/ViniciusOliver13"><b>Antonio Vinícius</b></a>
          </sub>
        </a>
      </td>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/140117398?v=4" width="100px;" alt="Foto de Marcelo"/><br>
          <sub>
            <a href="https://github.com/marceloDev0"><b>Marcelo Augusto</b></a>
          </sub>
        </a>
      </td>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/146675089?v=4" width="100px;" alt="Foto de Dinarte"/><br>
            <sub>
              <a href="https://github.com/dinarteefilho"><b>Dinarte Filho</b></a>
            </sub>
        </a>
      </td>
    </tr>
  </table>
</div>
