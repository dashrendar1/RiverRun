from django.conf.urls import url
from .views import *

urlpatterns = [
    url(r'^', Ingreso, name ="Ingreso"),
]
