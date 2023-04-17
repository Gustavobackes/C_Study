// Definição do TAD Aluno
class Aluno {
  constructor(nome, nota, status) {
    this.nome = nome;
    this.nota = nota;
    this.status = status;
  }
}

// Definição da classe Disciplina
class Disciplina {
  constructor() {
    this.listaChamada = [];
    this.limiteAlunos = 40;
  }

  incluirAluno(aluno) {
    if (this.listaChamada.length < this.limiteAlunos) {
      this.listaChamada.push(aluno);
      console.log(`Aluno ${aluno.nome} incluído na lista de chamada.`);
    } else {
      console.log("Não é possível incluir mais alunos na lista de chamada.");
    }
  }

  getAlunoInput() {
    const name = prompt("Nome do aluno: ");
    const note = prompt("Nota do aluno: ");
    const stats = prompt("Status do aluno:");
    this.incluirAluno(new Aluno(name, note, stats));
  }

  excluirAluno() {
    const nome = prompt("Nome do aluno a ser excluido: ");
    const index = this.listaChamada.findIndex((aluno) => aluno.nome === nome);
    if (index !== -1) {
      this.listaChamada.splice(index, 1);
      console.log(`Aluno ${nome} excluído da lista de chamada.`);
    } else {
      console.log(`Aluno ${nome} não encontrado na lista de chamada.`);
    }
  }

  ordenarPorNota() {
    this.listaChamada.sort((a, b) => b.nota - a.nota);
    console.log("Lista de chamada ordenada por nota:");
    this.mostrarListaChamada();
  }

  mostrarListaChamada() {
    let listaAlunos = [];

    this.listaChamada.forEach((aluno) => {
      listaAlunos.push(
        `${aluno.nome} - Nota: ${aluno.nota} - Status: ${aluno.status}`
      );
    });

    alert(`Lista de alunos: 
        ${listaAlunos.join("\n")}
    `);
  }

  mostrarListaChamadaAtiva() {
    let listaAlunos = [];

    console.log("Lista de chamada ativa:");
    const listaAtiva = this.listaChamada.filter(
      (aluno) => aluno.status === "ativa"
    );
    listaAtiva.forEach((aluno) =>
      listaAlunos.push(
        `${aluno.nome} - Nota: ${aluno.nota} - Status: ${aluno.status}`
      )
    );
    alert(`Lista de alunos ativos: 
    ${listaAlunos.join("\n")}
    `);
  }
}

// Criação da disciplina
const disciplina = new Disciplina();

// Inclusão de alunos
disciplina.incluirAluno(new Aluno("João", 8.5, "ativa"));
disciplina.incluirAluno(new Aluno("Maria", 9.0, "ativa"));
disciplina.incluirAluno(new Aluno("José", 7.0, "cancelada"));
disciplina.incluirAluno(new Aluno("Pedro", 6.5, "cancelada"));
disciplina.incluirAluno(new Aluno("Ana", 9.5, "ativa"));

disciplina.mostrarListaChamada();

function inicio() {
  const opcao = prompt(`
    Escolha uma opção:
    1. Incluir Aluno.
    2. Mostrar Lista de Alunos.
    3. Mostrar Lista de Alunos ordenada por nota.
    4. Mostrar Lista de Alunos ativos.
    5. Excluir Aluno.
    6. Sair
    `);
  do {
    switch (opcao) {
      case "1":
        disciplina.getAlunoInput();
        this.inicio();
        break;
      case "2":
        disciplina.mostrarListaChamada();
        this.inicio();
        break;
      case "3":
        disciplina.ordenarPorNota();
        this.inicio();
        break;
      case "4":
        disciplina.mostrarListaChamadaAtiva();
        this.inicio();
        break;
      case "5":
        disciplina.excluirAluno();
        this.inicio();
        break;
      default:
        break;
    }
  } while (opcao !== "Sair");
}
console.clear();
this.inicio();
