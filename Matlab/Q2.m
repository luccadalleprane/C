%Questão 2
clc;
clear;
close all;

% (Regra 1) Definindo n para h[n]
n_h = -5:5;
h = n_h;  % h[n] = n no intervalo -5 a 5

% (Regra 1) Definindo n para x[n]
n_x = 10:20;
x = ones(size(n_x));  % x[n] = 1 no intervalo 10 a 20

% Realizando a convolução
y = conv(x, h);
% A saída y(t) é a convolução de x(t) com h(t), multiplicada pelo passo de tempo.
% Definindo o eixo n para a saída
n_y = (n_x(1) + n_h(1)) : (n_x(end) + n_h(end));

% Plotando o resultado
stem(n_y, y, 'filled');
xlabel('n');
ylabel('y[n]');
title('Resposta do sistema y[n] = x[n] * h[n]');
grid on;
% (Regra 4) A resposta do sistema é plotada no intervalo correto, abrangendo toda a duração da convolução.
