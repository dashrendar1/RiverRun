from django.forms import ModelForm
from .models import *
from django import forms

class IngresoForm(ModelForm):
    solicitud = forms.CharField(label="Mensaje", required=True)
    class Meta:
        fields = ['solicitud']
        model = RiverRun
