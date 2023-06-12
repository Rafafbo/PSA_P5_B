function A = initialize(stepHeight)
A = zeros(6,size(10.7:-0.1:stepHeight,2));
idx = 1;
    for i = 10.7:-0.1:stepHeight
        Q_l = pos(0, i, 'l');
        Q_r = pos(0, i, 'r');
        A(:, idx) = [Q_l(1:3,1); Q_r(4:6,1)];
        idx = idx + 1;
    end
end