function [ pattern ] = add_noise( original_pattern, noise )
%distort_pattern Adauga zgomot unui sablon
    noise_mask = (rand(size(original_pattern)) >= noise) * 2 - 1;
    pattern = noise_mask .* original_pattern;
end

%% Tudor Berariu, 2014

