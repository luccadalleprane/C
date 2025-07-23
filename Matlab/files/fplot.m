x = linspace(-8,8,50); y = sin(x); z = cos(x);
figure(1)
plot(x,y)
figure(2)
plot(x, y, '--', x , z , '-.')