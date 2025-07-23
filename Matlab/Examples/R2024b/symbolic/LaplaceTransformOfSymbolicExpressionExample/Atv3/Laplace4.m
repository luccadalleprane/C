clc;
clear;

% Define variáveis simbólicas
syms n z Y

% Define a entrada x[n] = 0.8^n * u[n] (u[n] = 1 para n >= 0)
x = 0.8^n;

% Calcula a Transformada Z de x[n]
X = ztrans(x, n, z);

% Usa a propriedade de atraso: x[n-1] ↔ z^(-1) * X(z)
X_shift = X / z;

% Aplica a Transformada Z à equação de diferenças:
% y[n] - y[n-1] = x[n] + x[n-1]
% Y(z) * (1 - z^(-1)) = X(z) + z^(-1) * X(z)
eq = Y * (1 - 1/z) == X + X_shift;

% Resolve a equação para Y(z)
Ysol = solve(eq, Y);

% Aplica a Transformada Z inversa para obter y[n]
y_n = iztrans(Ysol, z, n);

% Exibe a solução simbólica de y[n]
disp('y[n] =')
pretty(simplify(y_n))

% Avalia y[n] para os valores de n de 0 até 20
n_vals = 0:20;  % Vetor de valores de n
y_vals = double(subs(y_n, n, n_vals));  % Substitui n na expressão e converte para números reais

% Plota a resposta discreta y[n] no intervalo 0 <= n <= 20
stem(n_vals, y_vals, 'filled')  % Gráfico de linhas verticais com bolinhas
xlabel('n')                     % Rótulo do eixo x
ylabel('y[n]')                  % Rótulo do eixo y
title('Solução y[n] da equação de diferenças')  % Título do gráfico
grid on                         % Ativa grade no gráfico
