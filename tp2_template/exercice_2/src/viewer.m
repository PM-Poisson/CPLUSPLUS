clear;
clf;

data;   % charge curve et polygon

dim = size(curve,1);

if dim == 1
    plot(curve(1,:), 'r');
    hold on;
    plot(polygon(1,:), 'bo-');
elseif dim == 2
    plot(curve(1,:),curve(2,:),'r','LineWidth',2);
    hold on
    plot(polygon(1,:),polygon(2,:),'bo--');
    axis equal
elseif dim == 3
    plot3(curve(1,:),curve(2,:),curve(3,:),'r','LineWidth',2);
    hold on
    plot3(polygon(1,:),polygon(2,:),polygon(3,:),'bo--');
    grid on
    axis equal
end

title("Bezier Curve Viewer");
