%Questão 2

% Passo de tempo
step = 0.01;
% O passo de tempo deve ser pequeno para representar com precisão sinais em tempo contínuo

% Definindo x(t)

t = -1:step:3;
x = zeros(size(t));
% O sinal de entrada x(t) = 1 para -1 ≤ t ≤ 3 é definido

t1 = (t >= -1) & (t <= 0.5);
t2 = (t > 0.5) & (t <= 3);
x(t1) = 0.6;
x(t2) = 0.3;
% (Regra 2) x(t) é definido por partes em intervalos que não se sobrepõem.

% Definindo h(t) = exp(-t) * u(t)

t1_h = 0:step:3;
t2_h = -1:step:-step;
% Os intervalos de tempo para as duas partes de h(t) são definidos de modo que não se sobreponham. (segunda regra)

h1 = exp(-t1_h);
h2 = zeros(size(t2_h));
h = [h2 h1];
% h(t) é definido no intervalo onde x(t) está definido. (primeira regra)

t_h = -1:step:3;
% (Regra 1) h(t) e x(t) são definidos no mesmo intervalo de tempo.
% (Regra 2 também se aplica) h(t) é definido por partes, e os intervalos não se sobrepõem.

% Convolução

y = conv(x, h) * step;
% (Regra 3) A saída y(t) é a convolução de x(t) com h(t), multiplicada pelo passo de tempo. (terceira regra)

% Tempo da saída

ty = -2:step:6;
% (Regra 4) O intervalo de tempo no qual o sinal de saída y será plotado é -2 ≤ t ≤ 6, ou seja, o dobro do intervalo em que os vetores x e h foram definidos.

% Plotando

plot(ty, y, 'LineWidth', 2);
xlabel('Tempo (s)');
ylabel('y(t)');
title('Resposta do Sistema y(t)');
grid on;
% (Regra 4) A resposta do sistema y(t) é plotada no intervalo correto, abrangendo toda a duração da convolução.
