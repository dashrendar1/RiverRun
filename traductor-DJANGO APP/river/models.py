from django.db import models

# Create your models here.

class RiverRun(models.Model):
    nombre = models.CharField(max_length=150)
    temperatura = models.CharField(max_length=10)
    viento = models.CharField(max_length=30)
    fuerza = models.CharField(max_length=20)
    estado = models.CharField(max_length=30)
    contaminacion = models.CharField(max_length=30)

class Promedios(models.Model):
    temp = models.DecimalField(max_digits = 12, decimal_places = 2, default = 0)
    viet = models.DecimalField(max_digits = 12, decimal_places = 2, default = 0)
    fuer = models.DecimalField(max_digits = 12, decimal_places = 2, default = 0)
