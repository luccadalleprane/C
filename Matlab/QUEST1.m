% Letra C
close all       
clc              
clear all        

% Cria vetor de tempo de 0 a 10 com 1000 pontos
t = linspace(0, 10, 1000);

% I. Coeficientes: a1 = 0, a0 = 3; Condições iniciais: y(0)=2, y'(0)=0
y1 = ss_diff2solve(0, 3, 2, 0, t);
figure; plot(t, y1); title('I'); xlabel('t'); ylabel('y(t)');

% II. Coeficientes: a1 = 2, a0 = 2; Condições iniciais: y(0)=-2, y'(0)=-1
y2 = ss_diff2solve(2, 2, -2, -1, t);
figure; plot(t, y2); title('II'); xlabel('t'); ylabel('y(t)');

% III. Coeficientes: a1 = 4, a0 = 13; Condições iniciais: y(0)=5, y'(0)=0
y3 = ss_diff2solve(4, 13, 5, 0, t);
figure; plot(t, y3); title('III'); xlabel('t'); ylabel('y(t)');

% IV. Coeficientes: a1 = 2, a0 = 1; Condições iniciais: y(0)=1, y'(0)=0
y4 = ss_diff2solve(2, 1, 1, 0, t);
figure; plot(t, y4); title('IV'); xlabel('t'); ylabel('y(t)');
