#include "material.h"

Material::Material() : albedo({255, 255, 255}), reflective(0) {}
Material::Material(Color _albedo) : albedo(_albedo), reflective(0) {}
Material::Material(Color _albedo, bool _reflective) : albedo(_albedo), reflective(_reflective) {}