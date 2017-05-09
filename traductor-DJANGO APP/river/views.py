from django.shortcuts import render, redirect
from django.views.generic import *
from .models import *
from django.core.urlresolvers import reverse_lazy, reverse
from django.contrib.auth.mixins import LoginRequiredMixin
from django.http import HttpResponseRedirect
from .forms import *
from decimal import Decimal
from django.shortcuts import get_object_or_404
from django.template import Context
from django import forms

promediotemp = 0.00
promedioviento = 0.00
promediofuerza = 0.00

def Ingreso(request):
    lista = RiverRun.objects.all()
    pr = Promedios.objects.get(pk=1)
    if request.method == 'POST':
        form = IngresoForm(request.POST)
        cadena = []
        atributo = ""
        for i in request.POST['solicitud']:
            if i == 'a':
                atributo += '0'
            elif i == 'b':
                atributo += '1'
            elif i == 'c':
                atributo += '2'
            elif i == 'd':
                atributo += '3'
            elif i == 'e':
                atributo += '4'
            elif i == 'f':
                atributo += '5'
            elif i == 'g':
                atributo += '6'
            elif i == 'h':
                atributo += '7'
            elif i == 'i':
                atributo += '8'
            elif i == 'j':
                atributo += '9'
            elif i == 'k':
                atributo += '.'
            elif i == 'l':
                cadena.append(atributo)
                atributo = ''
            else:
                form = IngresoForm()
                context = Context({'lista':lista, 'form':form, 'error': 'Ingresó un caracter incorrecto'})
                return render(request, 'home.html', context)
        if pr.temp == 0:
            pr.temp = Decimal(cadena[0])
            pr.viet = Decimal(cadena[1])
            pr.fuer = Decimal(cadena[2])
        else:
            pr.temp = (pr.temp + Decimal(cadena[0]))/2
            pr.viet = (pr.viet + Decimal(cadena[1]))/2
            pr.fuer = (pr.fuer + Decimal(cadena[2]))/2
        if pr.temp > 0:
            if Decimal(cadena[0]) > (pr.temp - (pr.temp * Decimal(0.20))) and  Decimal(cadena[0]) < (pr.temp + (pr.temp * Decimal(0.20))):
                if Decimal(cadena[2]) > (pr.fuer - (pr.fuer * Decimal(0.20))) and  Decimal(cadena[2]) < (pr.fuer + (pr.fuer * Decimal(0.20))):
                    RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Normal", contaminacion="Normal")
                elif Decimal(cadena[2]) < (pr.fuer - (pr.fuer * Decimal(0.20))):
                    RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Sequia", contaminacion="Normal")
                elif Decimal(cadena[2]) > (pr.fuer - (pr.fuer * Decimal(0.20))):
                    RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Desbordamiento", contaminacion="Normal")
            elif Decimal(cadena[0]) < (pr.temp - (pr.temp * Decimal(0.20))):
                if Decimal(cadena[2]) > (pr.fuer - (pr.fuer * Decimal(0.20))) and  Decimal(cadena[2]) < (pr.fuer + (pr.fuer * Decimal(0.20))):
                    RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Normal", contaminacion="Frio (Peligro)")
                elif Decimal(cadena[2]) < (pr.fuer - (pr.fuer * Decimal(0.20))):
                    RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Sequia", contaminacion="Frio (Peligro)")
                elif Decimal(cadena[2]) > (pr.fuer - (pr.fuer * Decimal(0.20))):
                    RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Desbordamiento", contaminacion="Frio (Peligro)")
            elif Decimal(cadena[0]) > (pr.temp - (pr.temp * Decimal(0.20))):
                if Decimal(cadena[2]) > (pr.fuer - (pr.fuer * Decimal(0.20))) and  Decimal(cadena[2]) < (pr.fuer + (pr.fuer * Decimal(0.20))):
                    RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Normal", contaminacion="Caliente (Peligro)")
                elif Decimal(cadena[2]) < (pr.fuer - (pr.fuer * Decimal(0.20))):
                    RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Sequia", contaminacion="Caliente (Peligro)")
                elif Decimal(cadena[2]) > (pr.fuer - (pr.fuer * Decimal(0.20))):
                    RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Desbordamiento", contaminacion="Caliente (Peligro)")
        else:
            RiverRun.objects.create(nombre="Rio Cunori", temperatura=cadena[0], viento=cadena[1], fuerza=cadena[2], estado="Normal", contaminacion="Normal")
        pr.save()
        return HttpResponseRedirect(reverse('Ingreso'))
    else:
        form = IngresoForm()
        context = Context({'lista':lista, 'form':form, 'promedios':pr })
        return render(request, 'home.html', context)
