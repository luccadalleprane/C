% Questão 3

clc;              
clear;           
close all;        

% Passo de tempo (resolução do vetor de tempo)
step = 0.01;

% Cria vetor de tempo de 0 a 10 com passo de 0.01, foi escolhido esse valor para ficar igual ao tempo dos gráficos do enunciado
t = 0:step:10;

% Inicializa vetor x(t) com zeros do mesmo tamanho de t
x = zeros(size(t));

% Define x(t) como um pulso retangular entre t = 1 e t = 2
x((t >= 1) & (t <= 2)) = 1;

% Inicializa vetor h(t) (resposta ao impulso) com zeros
h = zeros(size(t));

% Define h(t) com o mesmo formato de x(t), ou seja, também um retângulo de t = 1 até t = 2
h((t >= 1) & (t <= 2)) = 1;

% Plotando o sinal x(t)
figure;
subplot(3,1,1);                  
plot(t, x, 'k', 'LineWidth', 2); 
xlabel('Tempo (s)');
ylabel('x(t)');
title('Sinal x(t)');
grid on;                         
axis([0 10 0 1.2]);              

% Plotando o sinal h(t)
subplot(3,1,2);                  
plot(t, h, 'k', 'LineWidth', 2); % Sinal h(t), igual a x(t)
xlabel('Tempo (s)');
ylabel('h(t)');
title('Sinal h(t)');
grid on;
axis([0 10 0 1.2]);

% Realiza a convolução de x(t) com h(t) e multiplica pelo passo para manter escala temporal correta
y = conv(x, h) * step;

% Cria vetor de tempo para a saída y(t), que terá duração maior devido à convolução
ty = 0:step:(length(y)-1)*step;

% Plotando y(t) = x(t) * h(t), a resposta do sistema à entrada x(t)
subplot(3,1,3);
plot(ty, y, 'k', 'LineWidth', 2); % Plota o resultado da convolução
xlabel('Tempo (s)');
ylabel('y(t)');
title('Resposta do sistema y(t) = x(t) * h(t)');
grid on;
axis([0 10 0 max(y)+0.5]);       
