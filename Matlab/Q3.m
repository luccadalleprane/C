%Questão 3
#Letra A
clc;
clear;
close all;
% Definindo o intervalo de n
n = 0:20;
% Entrada impulso (delta)
x_imp = [1, zeros(1, length(n)-1)];
% Inicializar a saída
y_imp = zeros(size(n));
% Implementação da equação de diferenças
for k = 3:length(n)
   y_imp(k) = -y_imp(k-1) - 0.5*y_imp(k-2) + ...
               0.2*x_imp(k) + 0.1*x_imp(k-1) + 0.1*x_imp(k-2);
end
% Plotar a resposta
stem(n, y_imp, 'filled');
xlabel('n');
ylabel('h[n]');
title('Resposta ao Impulso do Sistema');
grid on;
