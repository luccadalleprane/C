% Índices n
n = 0:60;

% Plotar gráfico do Teste I 
figure(1)
y1 = ss_de2solve(0.2, -0.63, 5, -3, n);
stem(n, y1)
title('I')
xlabel('n'); ylabel('y[n]'); grid on;

% Plotar gráfico do Teste II
figure(2)
y2 = ss_de2solve(1.3, 0.4, 0, 5, n);
stem(n, y2)
title('II')
xlabel('n'); ylabel('y[n]'); grid on;


% Plotar gráfico do Teste III

figure(3)
y3 = ss_de2solve(-0.49, 1, -3, -1, n);
stem(n, y3)
title('III')
xlabel('n'); ylabel('y[n]'); grid on;

% Plotar gráfico do Teste IV
figure(4)
y4 = ss_de2solve(-1.7, 0.85, 2, -2, n);
stem(n, y4)
title('IV')
xlabel('n'); ylabel('y[n]'); grid on;
