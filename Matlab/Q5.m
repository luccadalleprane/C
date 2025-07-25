
% Questão 5

clear; clc; close all;

%% a) Resposta ao impulso total h[n]
% Respostas dos subsistemas
h1 = [2 3 4];
h2 = [-1 3 1];
h3 = [1 1 -1];

% Conexão em paralelo: h_p[n] = h1[n] + h2[n]
h_p = h1 + h2; % vetor soma direta

% Conexão em cascata com S3: h[n] = h_p[n] * h3[n]
h_total = conv(h_p, h3);

% Plot da resposta ao impulso total
figure;
stem(0:length(h_total)-1, h_total, 'filled');
title('Resposta ao Impulso Total h[n]');
xlabel('n');
ylabel('h[n]');
grid on;

%% b) Resposta ao sinal de entrada x[n] = u[n] - u[n-2]

% Definindo x[n]
x = [1 1 zeros(1,10)]; % tamanho suficiente para ver a resposta

% Resposta do sistema: y[n] = x[n] * h[n]
y = conv(x, h_total);


% Plot da resposta y[n]
figure;
stem(0:length(y)-1, y, 'filled');
title('Resposta do Sistema Total y[n] ao Sinal de Entrada');
xlabel('n');
ylabel('y[n]');
grid on;

