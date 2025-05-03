#🚀 Sistema de Transporte Tipo Pórtico com Garra

Este projeto simula um sistema automatizado de transporte utilizando um modelo de pórtico com garra, desenvolvido com ESP32 e display OLED. Ele tem como objetivo representar o deslocamento da garra entre três postos distintos, acionado por botões físicos e com feedback visual e sonoro ao usuário.

##🎯 Funcionalidades
Seleção de destino através de botões com tratamento de debounce.

Simulação de movimento com buzzer e tempo proporcional à distância entre postos.

Indicação do posto atual com LEDs individuais.

Controle da garra com LEDs dedicados para abertura e fechamento.

Exibição de informações em tempo real no display OLED (posto atual, destino, estado da garra e status do sistema).

🛠️ Tecnologias e Componentes Utilizados
ESP32

Display OLED 0.96" I2C SSD1306

Botões Pushbutton (x3)

LEDs (x5)

Buzzer ativo

Linguagem C++ (Arduino)

📋 Como Funciona
Ao iniciar, o sistema sorteia aleatoriamente o posto inicial e mantém a garra aberta.

O usuário pode selecionar um dos três postos como destino através dos botões.

O sistema:

Fecha a garra.

Simula o tempo de movimentação conforme a distância entre postos.

Emite som com o buzzer durante o movimento.

Abre a garra ao chegar no novo posto.

Atualiza display e LEDs com o novo estado.

📦 Organização do Código
setup(): Inicialização de periféricos, display e interrupções.

loop(): Monitora mudanças no destino e aciona movimento se necessário.

Funções auxiliares como moverPara(), abrirGarra(), fecharGarra() e mostrarEstado() garantem modularidade e clareza.

📚 Finalidade
Este projeto tem fins didáticos e pode ser utilizado como base para estudos sobre sistemas embarcados, automação, lógica de controle e simulação de processos industriais.

👨‍💻 Autor
Desenvolvido por Danilo Santos

Projeto acadêmico com foco em sistemas embarcados e automação.
