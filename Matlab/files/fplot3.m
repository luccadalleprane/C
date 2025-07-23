subplot(2,2,1);
x = 0:0.01:10;
y1 = sin(x);
plot(x,y1)
title('Subplot 1: sen(x)')

subplot(2,2,2)
y2 = sin(2*x);
plot(x,y2)
title('Subplot 2: sen(2x)')

subplot(2,1,2);
x = 0:0.01:10;
y3 = sin(4*x);
plot(x,y3)
title('Subplot 3: sen(4x)')

