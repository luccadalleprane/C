clear all;
syms t;

% Exercício 1
figure(1)

yy1 = (2)*(heaviside(t) - heaviside(t-1));
yy2 = (1)*(heaviside(t-1) - heaviside(t-2));
yy3 =(t-1)*(heaviside(t-2) - heaviside(t-3));
yy4 = (2)*(heaviside(t-3) - heaviside(t-4));

ty = yy1 + yy2 + yy3 + yy4;
fplot( t,ty ,'LineWidth', 2);
title('X(t) - A')
axis([-2 5 -1 5])
grid on;

figure(2)

z1 = (t)*(heaviside(t) - heaviside(t-2));
z2 = (-1*t + 4)*(heaviside(t-2) - heaviside(t-3));
z3 = (-2*t + 7)*(heaviside(t-3) - heaviside(t-4));
z4 = (t-5)*(heaviside(t-4) - heaviside(t-5));

tx = z1 + z2 + z3 + z4;
fplot( t,tx ,'LineWidth', 2);
title('X(t) - B')
axis([-2 5 -2 3])
grid on;

% Exercício 2

%A

figure(3)

x1 = (2*t + 2)*(heaviside(t+1) - heaviside(t));
x2 = (-t + 2)*(heaviside(t) - heaviside(t-1));
x3 = (heaviside(t-1) - heaviside(t-2));
x4 = (-1*t+3)*(heaviside(t-2) - heaviside(t-3));

xt = x1 + x2 + x3 + x4;
fplot( t,xt ,'LineWidth', 2);
title('Xa(t)')
axis([-2 4 -1 3])
grid on;


%B

figure(4)

y1 = (1.5*t + 1.5)*(heaviside(t+1) - heaviside(t));
y2 = (-1.5*t + 1.5)*(heaviside(t) - heaviside(t-1));
y3 = (-1.5*t + 1.5)*(heaviside(t-1) - heaviside(t-2));
y4 = (1.5*t -4.5)*(heaviside(t-2) - heaviside(t-3));

yt = y1 + y2 + y3 + y4;

fplot(t , yt,'LineWidth', 2 );
title('Xb(t)');
axis([-2 4 -2 2])
grid on;

%Exercício 3

%A - xa(t)+xb(t)
figure(5)

at = xt + yt;

fplot(t , at , [-2, 4], 'LineWidth', 2);
title('Xa(t)+Xb(t)');
axis([-2 4 -2 5])
grid on;

%B - xa(t)xb(t)
figure(6)

bt = xt * yt;

fplot(t , bt , [-2, 4], 'LineWidth', 2);
title('Xa(t)*Xb(t)');
axis([-2 4 -3 4])
grid on;

%C - 2xa(t)−xb(t)+3
figure(7)

ct = (2*xt) - yt + 3;

fplot(t , ct , [-2, 4], 'LineWidth', 2);
title('2*Xa(t)-Xb(t)+3');
axis([-2 4 -1 8]);
grid on;

%Exercício 4
figure(8)

xx1 = (t + 1.5)*(heaviside(t+1.5) - heaviside(t+0.5));
xx2 = (heaviside(t+0.5) - heaviside(t));
xx3 = (heaviside(t) - heaviside(t-1));
xx4 = (-1*t + 2)*(heaviside(t-1) - heaviside(t-2));
xx5 = (-1*t + 2)*(heaviside(t-2) - heaviside(t-3));
xx6 = (t - 4)*(heaviside(t-3) - heaviside(t-4));

xxt = xx1 + xx2 + xx3 + xx4 + xx5 + xx6;

fplot(t , xxt,'LineWidth', 2 );
title('X(t)');
axis([-2 4 -5 5])
grid on;


%%%%%Exercício 4 - A - x(−t) %%%%%
figure(9)

xxt = xx1 + xx2 + xx3 + xx4 + xx5 + xx6;

fplot(t , xxt,'LineWidth', 2 );
title('x(-t)');
axis([-2 5 -5 5])
grid on;

%%%%%Exercício 4 - B - x(2t) %%%%%
figure(10)

xxt = xx1 + xx2 + xx3 + xx4 + xx5 + xx6;

%Substituição simbólica
xxt_2t = subs(xxt, t, 2*t);

fplot(t , xxt_2t,'LineWidth', 2 );
title('x(2t)');
axis([-2 4 -5 5])
grid on;

%%%%%Exercício 4 - C - x(t/2) %%%%%
figure(11)

xxt = xx1 + xx2 + xx3 + xx4 + xx5 + xx6;

%Substituição simbólica
x_t2 = subs(xxt, t, t/2);

fplot(t , x_t2,'LineWidth', 2 );
title('x(t/2)');
axis([-4 5 -3 3])
grid on;

%%%%%Exercício 4 - D - x(-t+3) %%%%%
figure(12)

xxt = xx1 + xx2 + xx3 + xx4 + xx5 + xx6;

%Substituição simbólica
xd_t = subs(xxt, t, -t + 3);

fplot(t , xd_t,'LineWidth', 2 );
title('x(−t+3)');
axis([-3 5 -2 2])
grid on;

%%%%%Exercício 4 - E - x(4*t-3) %%%%%
figure(13)

xxt = xx1 + xx2 + xx3 + xx4 + xx5 + xx6;

%Substituição simbólica
xe_t = subs(xxt, t, 4*t - 3);

fplot(t , xe_t,'LineWidth', 2 );
title('x(4t −3)');
axis([-3 5 -2 2])
grid on;
