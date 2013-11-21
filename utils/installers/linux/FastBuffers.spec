Name: FastBuffers
Version: VERSION
Release:	1%{?dist}
Summary: Java tool that generates source code to serialize data using FastCDR library.
License: LGPLv3
URL: http://eprosima.com
Source0: %{name}_%{version}_rpm.tar.gz
BuildArch: noarch
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
BuildRequires: antlr stringtemplate ant
Requires: antlr stringtemplate

%description

%prep
%setup -q -n %{name}

%build
ant -Dbuildrootdir="%{buildroot}" jar

%install
rm -rf %{buildroot}
ant -Dbuildrootdir="%{buildroot}" install

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
%{_datadir}/*
%attr(755,root,root) %{_bindir}/fastbuffers.sh

%changelog

