% Questão 4

% Parâmetros
N = 30; % n = 0,...,29
n = 0:N-1;

% Sinal de entrada x[n]
x = (0.95).^n .* cos(0.1*pi*n);

% Respostas ao impulso dos sistemas
h1 = [1 0.5];    % resposta de S1
h2 = [1 -0.8];   % resposta de S2

% Convolução
w_full = conv(x, h1);
y_full = conv(w_full, h2);

% Vamos pegar só as primeiras N = 30 amostras:
w = w_full(1:N);
y = y_full(1:N);
% Plot dos sinais solicitados
figure;
subplot(2,1,1);
stem(n, w, 'filled');
title('Saída do Subsistema S_1: w[n]');
xlabel('n'); ylabel('w[n]');
subplot(2,1,2);
stem(n, y, 'filled');
title('Saída Final y[n]');
xlabel('n'); ylabel('y[n]');
