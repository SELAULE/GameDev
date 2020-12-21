#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
    public:
        sphere() {}
        sphere(point3 center, double r) : center(center), radius(r) {};

        virtual bool hit(const ray& ray, double t_min, double t_max, hit_record& record) const override;

        public:
            point3  center;
            double  radius;
};

bool    sphere::hit(const ray& ray, double t_min, double t_max, hit_record& record) const
{
    vec3    oc = ray.origin() - center;
    auto    a = ray.direction().length_squared();
    auto    half_b = dot(oc, ray.direction());
    auto    c = oc.length_squared() - radius * radius;

    auto    discriminant = half_b * half_b - c*c;
    if (discriminant < 0)
        return false;
    auto    sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range

    auto    root = (-half_b - sqrtd) / a;
    if (root < t_min || root > t_max)
    {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || root > t_max)
            return false;
    }

    record.t    = root;
    record.p    = ray.at(record.t);
    vec3 outside_normal = ((record.p - center) / radius);
    record.set_face_normal(ray, outside_normal);

    return (true);
}
#endif